#include <stdio.h>

int main() {
    int i;

    printf("Illustrating the concept of multithreading:\n\n");

    printf("Thread 1 starts:\n");
    for (i = 1; i <= 5; i++) {
        printf("Thread 1: Number %d\n", i);
    }
    printf("Thread 1 finished\n\n");

    printf("Thread 2 starts:\n");
    for (i = 0; i < 5; i++) {
        printf("Thread 2: Letter %c\n", 'A' + i);
    }
    printf("Thread 2 finished\n\n");

    printf("Main program: all threads completed\n");

    return 0;
}
