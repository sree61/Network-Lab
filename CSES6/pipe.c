/* CREATION OF AN ONEWAY PIPE IN A SINGLE PROCESS */

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int pipefd[2],n;
	char buff[100];
	pipe(pipefd);
	printf("\nreadfd=%d",pipefd[0]);
	write(pipefd[1],"helloworld",12);
	n=read(pipefd[0],buff,sizeof(buff));
	printf("\n size of the data%d",n);
	printf("\n data from pipe:%s",buff);
}
