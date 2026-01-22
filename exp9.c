#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    int shmid;
    char *shared_memory;
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }
    shared_memory = (char *)shmat(shmid, NULL, 0);
    if (fork() == 0) {
        // Child process
        sleep(1);
        printf("Child Process Reads: %s\n", shared_memory);
        fflush(stdout);
        shmdt(shared_memory);
    } else {
        strcpy(shared_memory, "Hello from Parent Process");
        printf("Parent Process Writes: %s\n", shared_memory);
        fflush(stdout);
        wait(NULL);   // 🔥 IMPORTANT
        shmdt(shared_memory);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
