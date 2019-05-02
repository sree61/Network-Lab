#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSIZE 27
main()
{
    int i, a;
    int shmid, n;
    key_t key;
    int *shm, *s;
    key = 5678;
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
    shm = shmat(shmid, NULL, 0);
    printf("Enter the limit");
    scanf("%d", &n);
    s = shm;
    *s = n;
    s = s + 1;
    printf("\nEnter numbers");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        *s++ = a;
    }
    *s = NULL;
    while (*shm != '*')
        sleep(1);
}
