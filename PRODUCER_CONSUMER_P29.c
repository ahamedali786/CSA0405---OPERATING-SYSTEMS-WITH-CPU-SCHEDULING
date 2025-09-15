#include <stdio.h>

#define SIZE 5  

int buffer[SIZE];
int in = 0;      
int out = 0;     
int count = 0;   

void produce(int item) {
    if (count == SIZE) {
        printf("Buffer is FULL! Cannot produce.\n");
        return;
    }
    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;
    printf("Produced item: %d\n", item);
}

void consume() {
    if (count == 0) {
        printf("Buffer is EMPTY! Cannot consume.\n");
        return;
    }
    int item = buffer[out];
    out = (out + 1) % SIZE;
    count--;
    printf("Consumed item: %d\n", item);
}

void displayBuffer() {
    printf("Buffer contents: ");
    if (count == 0) {
        printf("[empty]\n");
        return;
    }
    int i = out;
    for (int j = 0; j < count; j++) {
        printf("%d ", buffer[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, item;
    printf("=== Producer-Consumer Simulation ===\n");

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Display Buffer\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                produce(item);
                break;
            case 2:
                consume();
                break;
            case 3:
                displayBuffer();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
