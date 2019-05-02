#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSIZE 27
main()
{
    int shmid, n, a[20], i;
    key_t key;
    int *shm, *s;
    key = 5678;
    shmid = shmget(key, SHMSIZE, 0666);
    shm = shmat(shmid, NULL, 0);
    s = shm;
    n = *s;
    s = s + 1;
    for (i = 0; i < n; i++)
    {
        a[i] = *s;
        s = s + 1;
    }
    printf("\nEven Numbers are:");
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);
    }
    printf("\nOdd Numbers are:");
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
            printf("%d ", a[i]);
    }
    *shm = '*';
    printf("\nIts done from client.\n\n\n");
}
