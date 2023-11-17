def karatsuba_multiplication(x, y):
    """Multiply two integers using Karatsuba's algorithm."""
    # Base case for recursion
    if x < 10 or y < 10:
        return x * y

    # Calculate the size of the numbers
    n = max(len(str(x)), len(str(y)))
    half = n // 2

    # Split the digit sequences about the middle
    high1, low1 = x // 10**half, x % 10**half
    high2, low2 = y // 10**half, y % 10**half

    # 3 calls made to numbers approximately half the size
    z0 = karatsuba_multiplication(low1, low2)
    z1 = karatsuba_multiplication((low1 + high1), (low2 + high2))
    z2 = karatsuba_multiplication(high1, high2)

    return (z2 * 10 ** (2 * half)) + ((z1 - z2 - z0) * 10 ** half) + z0

def main():
    # Accept user input

        # Here we are assuming the user will input valid integers
        x = int(input("Enter the first number to multiply: "))
        y = int(input("Enter the second number to multiply: "))

        result = karatsuba_multiplication(x, y)
        print(f"Result = {result}")


# The script starts here
if __name__ == "__main__":
    main()

import time

start_time = time.time()
# Run your algorithm here
end_time = time.time()

execution_time = end_time - start_time
print(f"Execution Time: {execution_time} seconds")

