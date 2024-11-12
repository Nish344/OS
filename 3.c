#include <stdio.h>
#include <stdlib.h>

// Initialize global variables for synchronization and buffer state
int mutex = 1;
int full = 0;
int empty = 3;  // Total buffer slots available
int x = 0;      // Item counter

// Producer function to produce an item
void producer() {
    --mutex;    // Enter critical section
    ++full;     // Increase count of full slots
    --empty;    // Decrease count of empty slots
    x++;        // Increase item counter

    printf("\nProducer produces item %d", x);

    ++mutex;    // Exit critical section
}

// Consumer function to consume an item
void consumer() {
    --mutex;    // Enter critical section
    --full;     // Decrease count of full slots
    ++empty;    // Increase count of empty slots

    printf("\nConsumer consumes item %d", x);
    x--;        // Decrease item counter

    ++mutex;    // Exit critical section
}

int main() {
    int n, i;

    printf("1. Press 1 for Producer\n"
           "2. Press 2 for Consumer\n"
           "3. Press 3 for Exit");

    // Main loop to allow user input for producing/consuming items
    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        // Switch case to handle producer, consumer, and exit options
        switch (n) {
            case 1:
                // Call producer if buffer is not full
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full!");
                }
                break;

            case 2:
                // Call consumer if buffer is not empty
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!");
                }
                break;

            case 3:
                // Exit the program
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select 1, 2, or 3.");
                break;
        }
    }

    return 0;
}
