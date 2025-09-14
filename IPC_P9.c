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

    // 1. Create a shared memory segment of 64 bytes
    shmid = shmget(IPC_PRIVATE, 64, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    // 2. Attach the shared memory
    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat failed");
        return 1;
    }

    // 3. Create a child process
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    // 4. Child process writes message
    if (pid == 0) {
        strcpy(data, "Hello from Child via Shared Memory");
        shmdt(data); // detach
    }
    // 5. Parent waits and reads message
    else {
        wait(NULL);
        printf("Parent reads: %s\n", data);
        shmdt(data);                       // detach
        shmctl(shmid, IPC_RMID, NULL);     // remove segment
    }

    return 0;
}

SAMPLE RUN:
Parent got: Hi from Child!
