#include <stdio.h>
#include <time.h>

int noOfDigit(long x) {
   int n = 0;
   while (x > 0) {
      x /= 10;
      n++;
   }
   return n;
}

void schonhageStrassenMultiplication(long a, long b, int n, int m) {
   int linearConvolution[n + m - 1];
   for (int i = 0; i < (n + m - 1); i++)
      linearConvolution[i] = 0;

   long p = a;
   for (int i = 0; i < m; i++) {
      a = p;
      for (int j = 0; j < n; j++) {
         linearConvolution[i + j] += (b % 10) * (a % 10);
         a /= 10;
      }
      b /= 10;
   }

   printf("The Linear Convolution is: ( ");
   for (int i = (n + m - 2); i >= 0; i--) {
      printf("%d ", linearConvolution[i]);
   }
   printf(")\n");

   long product = 0;
   int nextCarry = 0, base = 1;
   for (int i = 0; i < n + m - 1; i++) {
      linearConvolution[i] += nextCarry;
      product = product + (base * (linearConvolution[i] % 10));
      nextCarry = linearConvolution[i] / 10;
      base *= 10;
   }
   printf("The Product of the numbers is: %ld\n", product);
}

int main() {
   printf("Enter the numbers: ");
   long a, b;
   scanf("%ld %ld", &a, &b);
   int n = noOfDigit(a);
   int m = noOfDigit(b);

   clock_t start, end;
   double cpu_time_used;

   start = clock();
   schonhageStrassenMultiplication(a, b, n, m);
   end = clock();

   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("Time taken: %f seconds\n", cpu_time_used);

   return 0;
}
