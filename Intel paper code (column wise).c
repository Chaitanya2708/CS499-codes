#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct BigInteger
{
    int *digits;
    int length;
};

struct BigInteger initBigInteger(char *num_str)
{
    struct BigInteger result;
    int len = 0;
    while (num_str[len] != '\0')
    {
        len++;
    }
    result.digits = (int *)malloc(len * sizeof(int));
    result.length = len;
    for (int i = 0; i < len; i++)
    {
        result.digits[i] = num_str[len - i - 1] - '0';
    }
    return result;
}

void freeBigInteger(struct BigInteger *num)
{
    free(num->digits);
}

void printBigInteger(struct BigInteger num)
{
    for (int i = num.length - 1; i >= 0; i--)
    {
        printf("%d", num.digits[i]);
    }
    printf("\n");
}

struct BigInteger multiply(const struct BigInteger *num1, const struct BigInteger *num2)
{
    struct BigInteger result;
    result.length = num1->length + num2->length;
    result.digits = (int *)calloc(result.length, sizeof(int));

    for (int i = 0; i < num1->length; i++)
    {
        int carry = 0;
        for (int j = 0; j < num2->length; j++)
        {
            int product = num1->digits[i] * num2->digits[j] + result.digits[i + j] + carry;
            carry = product / 10;
            result.digits[i + j] = product % 10;
        }

        if (carry)
        {
            result.digits[i + num2->length] += carry;
        }
    }

    while (result.length > 1 && result.digits[result.length - 1] == 0)
    {
        result.length--;
    }

    return result;
}

int main()
{
    clock_t start_time, end_time;
    double execution_time;

    start_time = clock();

    struct BigInteger num1 = initBigInteger("114701722186227725530857903247788731566117812708912875331083418612132595800326");
    struct BigInteger num2 = initBigInteger("987643221443489764384795643298746382985736482736487365847365874387458437564327");

    struct BigInteger product_result = multiply(&num1, &num2);

    printBigInteger(product_result);

    end_time = clock();
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", execution_time);

    freeBigInteger(&num1);
    freeBigInteger(&num2);
    freeBigInteger(&product_result);

    return 0;
}