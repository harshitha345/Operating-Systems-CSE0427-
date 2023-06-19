#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 20

// Function to print even numbers
void *printEvenNumbers(void *arg) {
    for (int i = 2; i <= MAX_NUMBER; i += 2) {
        printf("Even Thread: %d\n", i);
        usleep(100000);  // Sleep for 100 milliseconds
    }

    pthread_exit(NULL);
}

// Function to print odd numbers
void *printOddNumbers(void *arg) {
    for (int i = 1; i <= MAX_NUMBER; i += 2) {
        printf("Odd Thread: %d\n", i);
        usleep(100000);  // Sleep for 100 milliseconds
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t evenThread, oddThread;

    // Create the even thread
    if (pthread_create(&evenThread, NULL, printEvenNumbers, NULL) != 0) {
        printf("Failed to create the even thread.\n");
        return 1;
    }

    // Create the odd thread
    if (pthread_create(&oddThread, NULL, printOddNumbers, NULL) != 0) {
        printf("Failed to create the odd thread.\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    return 0;
}

