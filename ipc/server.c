#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>
struct mymsg
{
	long type;
	char msg[30];
	char from[10];
};// creating user defined structure
struct mymsg r;
void main()
	{
	key_t key;
	int mqid,d;
	char buff[30];
	key=ftok(".",1);//generating key
	mqid=msgget(key,IPC_CREAT|0666);//creating message queue
	while(1)
	{
	d=msgrcv(mqid,&r,sizeof(struct mymsg),1,0);//receiving message
	printf("Received msg:%s is from %s\n",r.msg,r.from);//printing the receive message
	}
}
