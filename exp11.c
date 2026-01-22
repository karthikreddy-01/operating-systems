#include <stdio.h>
#include <pthread.h>
void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Hello from Thread %d\n", thread_id);
    return NULL;
}
int main() {
    pthread_t threads[3];
    int thread_ids[3];
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads have finished execution.\n");
    return 0;
}
