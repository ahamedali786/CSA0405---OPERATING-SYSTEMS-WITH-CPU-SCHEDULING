#include <stdio.h>

int main() {
    int i, j;
    int philosophers = 5; 
    int rounds = 3;  
         
    printf("Simulating Dining Philosophers Problem:\n\n");

    for (i = 1; i <= rounds; i++) {
        printf("Round %d:\n", i);

        for (j = 1; j <= philosophers; j++) {
            printf("Philosopher %d is thinking\n", j);
        }

        for (j = 1; j <= philosophers; j++) {
            printf("Philosopher %d is eating\n", j);
        }

        printf("\n");
    }

    printf("All philosophers finished eating.\n");
    return 0;
}

SAMPLE OUTPUT:
Simulating Dining Philosophers Problem:

Round 1:
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking
Philosopher 5 is thinking
Philosopher 1 is eating
Philosopher 2 is eating
Philosopher 3 is eating
Philosopher 4 is eating
Philosopher 5 is eating

Round 2:
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking
Philosopher 5 is thinking
Philosopher 1 is eating
Philosopher 2 is eating
Philosopher 3 is eating
Philosopher 4 is eating
Philosopher 5 is eating

Round 3:
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking
Philosopher 5 is thinking
Philosopher 1 is eating
Philosopher 2 is eating
Philosopher 3 is eating
Philosopher 4 is eating
Philosopher 5 is eating

All philosophers finished eating.

