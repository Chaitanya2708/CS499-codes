#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

// Define a complex number struct in C
typedef struct {
    double real;
    double imag;
} Complex;

// Function to create a complex number
Complex create_complex(double real, double imag) {
    Complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

// Function to multiply two complex numbers
Complex multiply_complex(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Function to add two complex numbers
Complex add_complex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract_complex(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// FFT function
void fft(Complex *a, int n, Complex *y, int inverse) {
    if (n == 1) {
        y[0] = a[0];
        return;
    }

    Complex w[n];
    for (int i = 0; i < n; i++) {
        double alpha = 2 * M_PI * i / n * (inverse ? -1 : 1);
        w[i] = create_complex(cos(alpha), sin(alpha));
    }

    Complex A0[n/2], A1[n/2];
    for (int i = 0; i < n / 2; i++) {
        A0[i] = a[i * 2];
        A1[i] = a[i * 2 + 1];
    }

    Complex y0[n/2], y1[n/2];
    fft(A0, n / 2, y0, inverse);
    fft(A1, n / 2, y1, inverse);

    for (int k = 0; k < n / 2; k++) {
        Complex wk = w[k];
        y[k] = add_complex(y0[k], multiply_complex(wk, y1[k]));
        y[k + n / 2] = subtract_complex(y0[k], multiply_complex(wk, y1[k]));
    }
}

// Function to perform 64-bit multiplication and return execution time
double multiply_64bit(uint64_t a, uint64_t b, uint64_t *result_high, uint64_t *result_low) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    __uint128_t result = (__uint128_t)a * b;  // Perform the multiplication
    *result_high = (uint64_t)(result >> 64);  // High part of the result
    *result_low = (uint64_t)(result & 0xFFFFFFFFFFFFFFFF);  // Low part of the result
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;  // Calculate execution time
    return cpu_time_used;
}

// Function to read a 64-bit number
uint64_t read_64bit() {
    uint64_t number;
    printf("Enter a number (0 to 2^64-1): ");
    scanf("%llu", &number);
    return number;
}

int main() {
    uint64_t a, b;
    uint64_t result_high, result_low;

    printf("Enter the first number:\n");
    a = read_64bit();

    printf("Enter the second number:\n");
    b = read_64bit();

    double exec_time = multiply_64bit(a, b, &result_high, &result_low);

    // Displaying the result in decimal format
    if (result_high > 0) {
        printf("Result: %llu%llu\n", result_high, result_low);
    } else {
        printf("Result: %llu\n", result_low);
    }
    printf("Execution time: %f seconds\n", exec_time);

    return 0;
}

