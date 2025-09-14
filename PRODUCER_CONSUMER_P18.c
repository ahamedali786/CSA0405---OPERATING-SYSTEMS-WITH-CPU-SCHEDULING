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
