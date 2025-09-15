#include <stdio.h>
#include <pthread.h>

void* myThread(void* arg) {
    int id = *(int*)arg;
    printf("Hello from thread %d\n", id);

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    if (pthread_create(&t1, NULL, myThread, &id1) != 0) {
        printf("Error creating thread 1\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, myThread, &id2) != 0) {
        printf("Error creating thread 2\n");
        return 1;
    }

    if (pthread_equal(t1, t2))
        printf("Threads are equal (same)\n");
    else
        printf("Threads are different\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have finished.\n");

    return 0;
}
