#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSIZE 27
main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;
    shmid = shmget(key, SHMSIZE, 0666);
    shm = shmat(shmid, NULL, 0);
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');
    *shm = '*';
    printf("\nIts done from client.\n\n\n");
}
