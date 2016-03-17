
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>    

int lg_network_bind(char *address, int port)
{

    int sockfd = -1;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	return -1;

#if 0
    int	flag = 0x01;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) == -1) {

	close(sockfd);
	return -1;
    }
#endif

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    if (address) addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {

	close(sockfd);
	return -1;
    }

    if (listen(sockfd, 1000) == -1) {

	close(sockfd);
	return -1;
    }

    return sockfd;
}

int main()
{

    int listenfd = lg_network_bind(NULL, 888);
    if (listenfd == -1) {

	fprintf(stdout, "lg_network_bind::err\n");
	return -1;
    }

    char buffer[1024];
    for (;;) {

	int sockfd = accept(listenfd, NULL, NULL);
	read(sockfd, buffer, 1024);
	fprintf(stdout, "%s\n", buffer);
    }

    return 0;
}



