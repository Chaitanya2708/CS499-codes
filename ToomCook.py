#toomcook

def split_number(n, m):
    n_str = str(n)
    x0 = int(n_str[-m:])
    x1 = int(n_str[-2*m:-m]) if len(n_str) > m else 0
    x2 = int(n_str[:-2*m]) if len(n_str) > 2*m else 0
    return x0, x1, x2

def toom_cook_mul(x, y):
    # Base case: simple multiplication for small numbers
    if x < 10 or y < 10:
        return x * y

    # Calculate size of the numbers
    m = max(len(str(x)), len(str(y))) // 2

    # Split the numbers into three parts
    x0, x1, x2 = split_number(x, m)
    y0, y1, y2 = split_number(y, m)

    # Evaluate the polynomials at 0, 1, and -1
    x_evaluations = [x0, x0 + x1 + x2, x0 - x1 + x2]
    y_evaluations = [y0, y0 + y1 + y2, y0 - y1 + y2]

    # Pointwise multiplications
    r = [toom_cook_mul(x_eval, y_eval) for x_eval, y_eval in zip(x_evaluations, y_evaluations)]

    # Interpolate results (reconstruction)
    result = r[0] + ((r[2] - r[0] - r[1]) // 2) * 10**m + r[1] * 10**(2*m)
    return result

# Driver Code
if __name__ == "__main__":
    n = int(input("Enter the first number: "))
    m = int(input("Enter the second number: "))
    print(f"The result of {n} multiplied by {m} is {toom_cook_mul(n, m)}")

import time

start_time = time.time()
# Run your algorithm here
end_time = time.time()

execution_time = end_time - start_time
print(f"Execution Time: {execution_time} seconds")

