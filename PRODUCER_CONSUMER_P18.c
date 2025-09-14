#include <stdio.h>

#define SIZE 5  

int main() {
    int buffer[SIZE], count = 0;
    int n, i;

    printf("Producer-Consumer Simulation\n");

    printf("Enter number of items to produce (max %d): ", SIZE);
    scanf("%d", &n);
    if (n > SIZE) n = SIZE;

    printf("\nProducing items...\n");
    for (i = 0; i < n; i++) {
        buffer[count++] = i + 1; 
        printf("Produced item: %d | Buffer size: %d\n", buffer[i], count);
    }

    printf("\nConsuming items...\n");
    for (i = 0; i < n; i++) {
        printf("Consumed item: %d | Buffer size before consuming: %d\n", buffer[i], count);
        count--;
    }

    printf("\nAll items produced and consumed.\n");
    return 0;
}

SAMPLE INPUT:
Producer-Consumer Simulation
Enter number of items to produce (max 5): 3

SAMPLE OUTPUT:
Producing items...
Produced item: 1 | Buffer size: 1
Produced item: 2 | Buffer size: 2
Produced item: 3 | Buffer size: 3

Consuming items...
Consumed item: 1 | Buffer size before consuming: 3
Consumed item: 2 | Buffer size before consuming: 2
Consumed item: 3 | Buffer size before consuming: 1

All items produced and consumed.
