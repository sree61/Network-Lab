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
struct mymsg m;
void main()
{
	key_t key;
	int mqid,d;
	char buff[30];
	key=ftok(".",1);//generating key
	mqid=msgget(key,IPC_CREAT|0666);//creating message queue
	while(1)
	{
		printf("Enter msg:");
		gets(buff);
		strcpy(m.msg,buff);//copying the message in buffer to structure variable msg
		m.type=1; // storing message type as one
		strcpy(m.from,"Client");//copying the source of message to structure variable msg
		d=msgsnd(mqid,&m,sizeof(struct mymsg),0); //sending messages
	}
}
