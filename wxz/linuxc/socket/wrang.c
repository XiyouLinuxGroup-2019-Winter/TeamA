#include "wrang.h"
void sys_err(const char* s)
{
    perror(s);
    exit(1);
}
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n=0;

again:
	if ((n=accept(fd,sa,salenptr))<0) 
    {
		if ((errno==ECONNABORTED)||(errno==EINTR))
			goto again;
		else
			sys_err("accept error");
	}
	return n;
}
int Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    int n=0;
	if((n=bind(fd,sa,salen))<0)
		sys_err("bind error");
    return n;
}
int Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{

    int n=0;

	if((n=connect(fd,sa,salen))<0)
		sys_err("connect error");
    return n;
}
int Listen(int fd, int backlog)
{
    int n;
	if((n=listen(fd,backlog))<0)
		sys_err("listen error");
    return n;
}
int Socket(int family, int type, int protocol)
{
   int n;
	if((n=socket(family,type,protocol))<0)
		sys_err("socket error");
	return n;
}
ssize_t Read(int fd, void *ptr, size_t nbytes)
{
    ssize_t n;
again:
	if ((n=read(fd,ptr,nbytes))==-1) 
    {
		if(errno==EINTR)
			goto again;
		else
			return -1;
	}
	return n;
}
ssize_t Write(int fd, const void *ptr, size_t nbytes)
{
    ssize_t n;

again:
	if((n=write(fd,ptr,nbytes))==-1)
    {
		if(errno==EINTR)
			goto again;
		else
			return -1;
	}
	return n;
}
int Close(int fd)
{
    int n;
	if((n=close(fd))==-1)
		sys_err("close error");

    return n;
}
ssize_t Readn(int fd, void *vptr, size_t n)
{
    
}
ssize_t Writen(int fd, const void *vptr, size_t n)
{

}
ssize_t my_read(int fd, char *ptr)
{

}
ssize_t Readline(int fd, void *vptr, size_t maxlen)
{

}