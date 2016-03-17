
#include "lg_network.h"

int lg_network_fdmax(int fdmax)
{

    struct rlimit rt;
    bzero(&rt, sizeof(struct rlimit));
    rt.rlim_max = rt.rlim_cur = fdmax;
    return setrlimit(RLIMIT_NOFILE, &rt);
}

int lg_network_noblocking(int sockfd)
{

    int opts = -1;
    if ((opts = fcntl(sockfd, F_GETFD, 0)) == NETWORK_ERROR)
	return NETWORK_ERROR;

    if ((fcntl(sockfd, F_SETFL, opts | O_NONBLOCK)) == NETWORK_ERROR)
	return NETWORK_ERROR;

    return NETWORK_SUCCESS;
}

int lg_network_check(int sockfd)
{

    int error = -1;
    socklen_t len = sizeof(int);
    if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len) == NETWORK_ERROR)
	return NETWORK_ERROR;

    return error;
}

int lg_network_not_time_wait(int sockfd)
{

    struct linger opt;
    opt.l_onoff = 0x01;
    opt.l_linger = 0x00;
    if (setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &opt, sizeof(struct linger)) == NETWORK_ERROR)
	return NETWORK_ERROR;

    return NETWORK_SUCCESS;
}

int lg_network_set_kernel_buffer(int sockfd, int send_size, int recv_size)
{

    int size;
    if ((size = send_size))
	if (setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &size, sizeof(int)) == NETWORK_ERROR)
	    return NETWORK_ERROR;

    if ((size = recv_size))
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(int)) == NETWORK_ERROR)
	    return NETWORK_ERROR;

    return NETWORK_SUCCESS;
}

int lg_network_get_kernel_buffer(int sockfd, int *send_size, int *recv_size)
{

    socklen_t len = sizeof(int);
    if (getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, send_size, &len) == NETWORK_ERROR)
	return NETWORK_ERROR;

    if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, recv_size, &len) == NETWORK_ERROR)
	return NETWORK_ERROR;

    return NETWORK_SUCCESS;
}

int lg_network_bind(char *address, int port)
{

    int sockfd = -1;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == NETWORK_ERROR)
	return NETWORK_ERROR;

    int	flag = 0x01;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) == NETWORK_ERROR) {

	close(sockfd);
	return NETWORK_ERROR;
    }

    if (lg_network_noblocking(sockfd) == NETWORK_ERROR) {

	close(sockfd);
	return NETWORK_ERROR;
    }

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    if (address)addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == NETWORK_ERROR) {

	close(sockfd);
	return NETWORK_ERROR;
    }

    if (listen(sockfd, 1000) == NETWORK_ERROR) {

	close(sockfd);
	return NETWORK_ERROR;
    }

    return sockfd;
}
int lg_network_accept(int listenfd)
{

    int sockfd = accept(listenfd, NULL, NULL, NULL);
    if (sockfd == NETWORK_ERROR) {

	switch (errno) {

	    case EAGAIN:
	    case EINTR:
	    case EPERM:
	    case EMFILE: 
		return NETWORK_SUCCESS;

	    case EBADF:
	    case EFAULT:
	    case EINVAL:
	    case ENFILE:
	    case ENOMEM:
	    default:
		return NETWORK_ERROR;
	}
    }

    return sockfd;
}

int lg_network_connect(char *address, int port)
{

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));

    addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    int sockfd = -1;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == NETWORK_ERROR)
	return NETWORK_ERROR;

    if (lg_network_noblocking(sockfd) == NETWORK_ERROR) {

	close(sockfd);
	return NETWORK_ERROR;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0)
	return sockfd;

    if (errno == EINPROGRESS)
	return sockfd;

    close(sockfd);
    return NETWORK_ERROR;
}

ssize_t lg_network_send(int sockfd, void *buffer, size_t buffer_size)
{

    ssize_t size = write(sockfd, buffer, buffer_size);
    if (size == NETWORK_ERROR) {

	if (errno == EINTR || errno == EAGAIN)
	    return NETWORK_SUCCESS;

	if (lg_network_check(sockfd) == NETWORK_SUCCESS)
	    return NETWORK_SUCCESS;

	return NETWORK_ERROR;

    } else if (size == 0) {

	return NETWORK_ERROR;
    }

    return size;
}

ssize_t lg_network_recv(int sockfd, void *buffer, size_t buffer_size)
{

    ssize_t size = read(sockfd, buffer, buffer_size);
    if (size == NETWORK_ERROR) {

	if (errno == EINTR || errno == EAGAIN)
	    return NETWORK_SUCCESS;

	if (lg_network_check(sockfd) == NETWORK_SUCCESS)
	    return NETWORK_SUCCESS;

	return NETWORK_ERROR;

    } else if (size == 0) {

	return NETWORK_ERROR;
    }

    return size;
}

