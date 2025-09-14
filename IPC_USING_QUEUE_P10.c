#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    pid_t pid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    if (key == -1) {
        perror("ftok failed");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
     
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from Child via Message Queue!");
        if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
            perror("msgsnd failed");
        }
    } else {
  
        wait(NULL);
        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
            perror("msgrcv failed");
            return 1;
        }
        printf("Parent received: %s\n", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);  
    }
    return 0;
}
SAMPLE OUTPUT:
Parent received: Hello from Child via Message Queue!
