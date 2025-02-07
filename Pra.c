#include <stdio.h>
#include <time.h>

// Function to create a delay of specified seconds
void delay(int number_of_seconds) {
    // Converting time into milliseconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // Looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int main() {
    for (int i = 0; i < 100; i++) {
        // Delay of one second
        delay(1);
        printf("%d seconds have passed\n", i + 1);
    }
    return 0;
}
