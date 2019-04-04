#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void fib(void *p1)
{
    int a=0, b=1,c;
    int i,l;
    printf("Enter the limit:");
    scanf("%d",&l);
    printf("\nFibnocci series is:");
    printf("%d\t%d",a,b);
    for(i=2;i<=l;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf("\t%d",c);
    }
}
void prime(void *p2)
{
    int n,i=2;
    int cl,j;
    printf("\nEnter the limit:");
    scanf("%d",&n);
    printf("\nPrime number are:");
    while(i<=n)
    {
        if(i==2)
        {
            printf("%d\t",i);
            i++;
        }
        else
        {
            cl=0;
            for(j=1;j<=i;j++)
            {
                if(i%j==0)
                {
                    cl++;
                }
            }
            if(cl==2)
            {
                printf("%d\t",i);
                i++;
            }
            else
            {
                i++;
            }
        }
        
    }
}
void main()
{
    pthread_t p1,p2;
    pthread_create(&p1,NULL,(void*)&fib,NULL);
    pthread_join(p1,NULL);
    pthread_create(&p2,NULL,(void*)&prime,NULL);
    pthread_join(p2,NULL);
}
