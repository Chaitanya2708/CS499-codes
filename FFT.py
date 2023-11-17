#fft

import numpy as np

def fft_multiply(num1, num2):
    # Convert integers to polynomials (reversed because the coefficient of the highest degree comes first)
    poly1 = [int(i) for i in str(num1)][::-1]
    poly2 = [int(i) for i in str(num2)][::-1]

    # The length for the FFT should be at least the sum of the lengths of the input sequences to allow space for the result
    fft_length = 1 << (len(poly1) + len(poly2) - 1).bit_length()  # smallest power of 2 sufficient for the multiplication result

    # Convert the integer sequences to point-value form (in-place)
    poly1_vals = np.fft.fft(poly1, fft_length)
    poly2_vals = np.fft.fft(poly2, fft_length)

    # Point-wise multiplication
    result_vals = np.multiply(poly1_vals, poly2_vals)

    # Convert the point-value form back to the coefficient representation
    result_poly = np.fft.ifft(result_vals)
    result_poly = np.round(result_poly.real)

    # Handle carries for coefficients
    carry = 0
    for idx, coeff in enumerate(result_poly):
        coeff = int(coeff) + carry
        carry, coeff = divmod(coeff, 10)
        result_poly[idx] = coeff
        if carry and idx == len(result_poly) - 1:
            result_poly = np.append(result_poly, carry)  # Add the carry as a new coefficient

    # Convert polynomial back to integer
    result = 0
    for coeff in reversed(result_poly):
        result = (result * 10) + int(coeff)

    return result

def main():
    # Input two large numbers
    print("Enter the first large number:")
    num1 = int(input().strip())
    print("Enter the second large number:")
    num2 = int(input().strip())

    # Call the fft_multiply function and print out the result
    product = fft_multiply(num1, num2)
    print(f"Product = {product}")

# This is the standard boilerplate that calls the main() function
if __name__ == '__main__':
    main()

import time

start_time = time.time()
# Run your algorithm here
end_time = time.time()

execution_time = end_time - start_time
print(f"Execution Time: {execution_time} seconds")

