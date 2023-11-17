#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024

// Function prototypes
long long toom_cook_mul(long long x, long long y);
void split_number(long long n, int m, long long *parts);

void split_number(long long n, int m, long long *parts) {
    for (int i = 0; i < 3; i++) {
        parts[i] = n % (long long)pow(10, m);
        n /= (long long)pow(10, m);
    }
}

long long toom_cook_mul(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int m = MAX_SIZE / 6;
    long long x_parts[3], y_parts[3];
    split_number(x, m, x_parts);
    split_number(y, m, y_parts);

    long long p0 = x_parts[0] * y_parts[0];
    long long p1 = (x_parts[0] + x_parts[1] + x_parts[2]) * (y_parts[0] + y_parts[1] + y_parts[2]);
    long long p2 = (x_parts[0] - x_parts[1] + x_parts[2]) * (y_parts[0] - y_parts[1] + y_parts[2]);

    long long result = p0 + ((p2 - p0 - p1) / 2) * (long long)pow(10, m) + p1 * (long long)pow(10, 2 * m);
    return result;
}

int main() {
    long long n, m;
    printf("Enter the first number: ");
    scanf("%lld", &n);
    printf("Enter the second number: ");
    scanf("%lld", &m);

    clock_t start_time = clock();
    long long result = toom_cook_mul(n, m);
    clock_t end_time = clock();

    printf("The result of %lld multiplied by %lld is %lld\n", n, m, result);
    printf("Execution Time: %lf seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}
