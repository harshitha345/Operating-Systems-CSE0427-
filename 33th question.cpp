#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to check if a number is prime
int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to generate the Fibonacci series
void generateFibonacci(int n) {
    int prev = 0;
    int current = 1;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", prev);

        int next = prev + current;
        prev = current;
        current = next;
    }

    printf("\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Failed to fork.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        generateFibonacci(10);
    } else {
        // Parent process
        int status;
        wait(&status);

        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {
            if (isPrime(i)) {
                printf("%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}

