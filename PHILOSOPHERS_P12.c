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
