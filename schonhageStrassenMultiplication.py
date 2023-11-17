import time

def no_of_digit(x):
    return len(str(x))

def schonhage_strassen_multiplication(a, b, n, m):
    linear_convolution = [0] * (n + m - 1)

    p = a
    for i in range(m):
        a = p
        for j in range(n):
            linear_convolution[i + j] += (b % 10) * (a % 10)
            a //= 10
        b //= 10

    print("The Linear Convolution is: (", end=" ")
    for i in reversed(linear_convolution):
        print(i, end=" ")
    print(")")

    product = 0
    next_carry = 0
    base = 1
    for i in linear_convolution:
        i += next_carry
        product += (base * (i % 10))
        next_carry = i // 10
        base *= 10

    print("The Product of the numbers is:", product)

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    n = no_of_digit(a)
    m = no_of_digit(b)

    start_time = time.time()
    schonhage_strassen_multiplication(a, b, n, m)
    end_time = time.time()

    print("Time taken: {:.6f} seconds".format(end_time - start_time))

if __name__ == "__main__":
    main()
