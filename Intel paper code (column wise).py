# Intel paper code column wise
# long multiplication

import time


class BigInteger:
    def __init__(self, num_str):
        self.digits = [int(digit) for digit in reversed(
            num_str)]  # Store digits in reverse order

    def __str__(self):
        return ''.join(map(str, reversed(self.digits)))

    def __mul__(self, other):
        result = [0] * (len(self.digits) + len(other.digits))

        for i in range(len(self.digits)):
            carry = 0
            for j in range(len(other.digits)):
                product = self.digits[i] * \
                    other.digits[j] + result[i + j] + carry
                carry = product // 10
                result[i + j] = product % 10

            if carry:
                result[i + len(other.digits)] += carry

        while len(result) > 1 and result[-1] == 0:
            result.pop()

        return BigInteger(''.join(map(str, reversed(result))))


num1 = BigInteger(
    "114701722186227725530857903247788731566117812708912875331083418612132595800326")
num2 = BigInteger(
    "987643221443489764384795643298746382985736482736487365847365874387458437564327")

product_result = num1 * num2
print(product_result)


start_time = time.time()
end_time = time.time()

execution_time = end_time - start_time
print(f"Execution Time: {execution_time} seconds")