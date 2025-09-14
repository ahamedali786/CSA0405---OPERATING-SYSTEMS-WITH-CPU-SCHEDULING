#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int shmid;
    char *data;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, 64, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        strcpy(data, "Hello from Child via Shared Memory");
        shmdt(data);
    }
    else {
        wait(NULL);
        printf("Parent reads: %s\n", data);
        shmdt(data);                      
        shmctl(shmid, IPC_RMID, NULL);     
    }

    return 0;
}

SAMPLE RUN:
Parent got: Hi from Child!
