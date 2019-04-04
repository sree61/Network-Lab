#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
struct mymsg
{
	long type;
	char msg[30];
	char from[10];
};// creating user defined structure
struct mymsg m,r;
main()
{
	key_t key;
	pid_t pid;
	int mqid,d;
	char buff[30];
	key=ftok(".",1);//generating key
	mqid=msgget(key,IPC_CREAT|0666);//creating message queue
	pid=fork();//creating a child process
	if(pid==0)//child
	{
		while(1)
		{
			sleep(1);
			printf("Enter msg:");
			gets(buff);
			strcpy(m.msg,buff);
			m.type=1;
			strcpy(m.from,"child");
			d=msgsnd(mqid,&m,sizeof(struct mymsg),0); //sending message
		}
	}
	if(pid>0)
		//parent
	{
		while(1)
		{
			d=msgrcv(mqid,&r,sizeof(struct mymsg),1,0);//receiving message
			printf("Received msg:%s is from %s\n",r.msg,r.from);//printing the received message
		}
	}
}
