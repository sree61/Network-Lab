#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSIZE 27
main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;
    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
    shm = shmat(shmid, NULL, 0);
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = NULL;
    while (*shm != '*')
        sleep(1);
}
