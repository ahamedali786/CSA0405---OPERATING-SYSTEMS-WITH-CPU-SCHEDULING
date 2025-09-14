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

SAMPLE OUTPUT:
Illustrating the concept of multithreading:

Thread 1 starts:
Thread 1: Number 1
Thread 1: Number 2
Thread 1: Number 3
Thread 1: Number 4
Thread 1: Number 5
Thread 1 finished

Thread 2 starts:
Thread 2: Letter A
Thread 2: Letter B
Thread 2: Letter C
Thread 2: Letter D
Thread 2: Letter E
Thread 2 finished

Main program: all threads completed
