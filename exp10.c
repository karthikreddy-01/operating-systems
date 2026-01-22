#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
struct message {
    long msg_type;
    char msg_text[100];
};
int main() {
    int msgid;
    struct message msg;
    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("msgget failed");
        return 1;
    }
    if (fork() == 0) {
        msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
        printf("Child Process Received: %s\n", msg.msg_text);
    } else {
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello from Parent Process");
        msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);
        printf("Parent Process Sent: %s\n", msg.msg_text);
        wait(NULL);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}
