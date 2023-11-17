#include <stdio.h>
#include <string.h>
#include <time.h>

#define NUM_SIZE 80

// Function to perform Urdhva Triyagbhyam multiplication for 128-bit numbers
void urdhvaTriyagbhyamMultiply(int num1[], int num2[], int result[]) {
    int carry = 0;

    for (int i = 0; i < NUM_SIZE; ++i) {
        for (int j = 0; j < NUM_SIZE; ++j) {
            int product = num1[i] * num2[j] + result[i + j] + carry;

            result[i + j] = product % 10; // Stores the result in the appropriate position
            carry = product / 10; // Updates carry for the next iteration
        }

        while (carry) {
            result[i + NUM_SIZE] += carry % 10;
            carry /= 10;
        }
    }
}

int main() {
    // example
    char num1Str[] = "114701722186227725530857903247788731566117812708912875331083418612132595800326";
    char num2Str[] = "987643221443489764384795643298746382985736482736487365847365874387458437564327";

    int num1[NUM_SIZE], num2[NUM_SIZE], result[2 * NUM_SIZE] = {0};

    // Converting strings to integer arrays
    // Converting strings to integer arrays
    for (int i = 0; i < NUM_SIZE; ++i) {
        num1[i] = num1Str[NUM_SIZE - 1 - i] - '0';
        if (num1[i] < 0) {
            num1[i] = 0;
    }

        num2[i] = num2Str[NUM_SIZE - 1 - i] - '0';
        if (num2[i] < 0) {
            num2[i] = 0;
    }
}


    clock_t start_time = clock();

    urdhvaTriyagbhyamMultiply(num1, num2, result);

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Result: ");
    int startPrinting = 2 * NUM_SIZE - 1;
    while (startPrinting > 0 && result[startPrinting] == 0) {
        startPrinting--;
    }
    for (int i = startPrinting; i >= 4; --i) {
        printf("%d", result[i]);
    }


    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}