#include <arpa/inet.h>
#include <sys/select.h>

typedef struct udp_session_t {
	int fd;
	struct sockaddr_in laddr;
	socklen_t laddr_len;
	struct sockaddr_in raddr;
	socklen_t raddr_len;
	struct udp_session_t* next;
	time_t atime;	/// Session last active time
} udp_session_t;

udp_session_t* udps_search_byladdr(struct sockaddr_in);

udp_session_t* udps_add(udp_session_t);

udp_session_t* udps_search_byfd(int);

int udps_cleanup(int ttl);

int udps_fdset(fd_set*);
