#include<stdio.h>
#include<stdlib.h>
void main()
{
	int pipefd[2],n,pid;
	char buff[100];
	pipe(pipefd);
	printf("\n readfd=%d",pipefd[0]);
	printf("\n writefd=%d",pipefd[1]);
	pid=fork();
	if(pid==0)
	{
		close(pipefd[0]);
		printf("\n CHILD PROCESS SENDING DATA\n");
		write(pipefd[1],"hello world",12);
	}
	else
	{
		close(pipefd[1]);
		printf("PARENT PROCESS RECEIVES DATA\n");
		n=read(pipefd[0],buff,sizeof(buff));
		printf("\n Size of data%d",n);
		printf("\n Data received from child throughpipe:%s\n",buff);
	}
}
