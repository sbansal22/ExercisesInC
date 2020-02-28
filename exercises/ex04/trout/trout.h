#ifndef TROUT_H
#define TROUT_H "trout.h"


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>

#define MAXLINE 4096
#define BUFSIZE 1500


typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;
typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef	void Sigfunc(int);


/* the following are a few definitions from Stevens' unp.h */

extern Sockaddr *sasend;    /* socket addresses for various purposes */
extern Sockaddr *sarecv;
extern Sockaddr *salast;
extern Sockaddr *sabind;

extern int max_ttl;
extern int nprobes;

extern socklen_t salen;
extern int datalen;

extern unsigned short sport;
extern unsigned short dport;
#define max(a,b) ((a) > (b) ? (a) : (b))

/* the following are prototypes for the Stevens utilities in util.c */

// int main (int argc, char **argv);

int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();
// char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
// void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
// int sock_cmp_addr(const struct sockaddr *sa1,
// 		  const struct sockaddr *sa2, socklen_t salen);
// void tv_sub (struct timeval *out, struct timeval *in);
// char *icmpcode_v4(int code);
// Sigfunc *Signal(int signo, Sigfunc *func);
// void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
// 	    const struct sockaddr *sa, socklen_t salen);
#endif
