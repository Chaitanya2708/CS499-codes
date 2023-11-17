#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Function to find the number of digits in a number
int numDigits(long long n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        ++count;
    }
    return count;
}

// Function to perform the Karatsuba multiplication
long long karatsubaMultiplication(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int n = fmax(numDigits(x), numDigits(y));
    int half = n / 2;

    long long high1 = x / pow(10, half);
    long long low1 = x % (long long)(pow(10, half));
    long long high2 = y / pow(10, half);
    long long low2 = y % (long long)(pow(10, half));

    long long z0 = karatsubaMultiplication(low1, low2);
    long long z1 = karatsubaMultiplication(low1 + high1, low2 + high2);
    long long z2 = karatsubaMultiplication(high1, high2);

    return (z2 * pow(10, 2 * half)) + ((z1 - z2 - z0) * pow(10, half)) + z0;
}

int main() {
    long long x, y, result;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Enter the first number to multiply: ");
    scanf("%lld", &x);
    printf("Enter the second number to multiply: ");
    scanf("%lld", &y);

    start_time = clock();
    result = karatsubaMultiplication(x, y);
    end_time = clock();

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Result = %lld\n", result);
    printf("Execution Time: %.11f seconds\n", cpu_time_used); // Precision set to 11 decimal places

    return 0;
}