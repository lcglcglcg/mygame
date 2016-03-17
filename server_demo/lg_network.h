
#ifndef	__LG_NETWORK_H__
#define	__LG_NETWORK_H__

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

#define	NETWORK_SUCCESS 0
#define	NETWORK_ERROR -1
#define	NETWORK_TIMEOUT -2
#define	NETWORK_SIGNALEINTR -3

#ifdef __cplusplus
extern "C" { 
#endif

    extern int lg_network_fdmax(int fdmax);
    extern int lg_network_noblocking(int sockfd);
    extern int lg_network_check(int sockfd);
    extern int lg_network_not_time_wait(int sockfd);
    extern int lg_network_set_kernel_buffer(int sockfd, int send_size, int recv_size);
    extern int lg_network_get_kernel_buffer(int sockfd, int *send_size, int *recv_size);

    extern int lg_network_bind(char *address, int port);
    extern int lg_network_accept(int listenfd);
    extern int lg_network_connect(char *address, int port);
    extern ssize_t lg_network_send(int sockfd, void *buffer, size_t buffer_size);
    extern ssize_t lg_network_recv(int sockfd, void *buffer, size_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif// __NETWORK_H__
