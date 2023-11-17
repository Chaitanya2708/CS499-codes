import time


class Solution:
    def makeLengthEqual(self, a, b):
        if len(a) == len(b):
            return
        if len(a) < len(b):
            self.makeLengthEqual(b, a)
            return
        while len(b) != len(a):
            b = "0" + b

    def removeLeadingZero(self, num):
        n = len(num) - 1
        for i in range(len(num) - 1):
            if num[i] != '0':
                n = i
                break
        num = num[n:]

    def multiply(self, num1, num2):
        self.makeLengthEqual(num1, num2)
        n = len(num1)
        carry = 0
        ans = ""

        for i in range(n - 1, -1, -1):
            _sum = 0
            k = i
            for j in range(n - 1, i - 1, -1):
                _sum += int(num1[j]) * int(num2[k])
                k += 1
            _sum += carry
            carry = _sum // 10
            ans += str(_sum % 10)

        for i in range(n - 2, -1, -1):
            _sum = 0
            k = 0
            for j in range(i, -1, -1):
                _sum += int(num1[j]) * int(num2[k])
                k += 1
            _sum += carry
            carry = _sum // 10
            ans += str(_sum % 10)

        if carry:
            ans += str(carry)

        ans = ans[::-1]
        self.removeLeadingZero(ans)
        return ans


if __name__ == "__main__":
    solution = Solution()

    num1 = "114701722186227725530857903247788731566117812708912875331083418612132595800326"
    num2 = "987643221443489764384795643298746382985736482736487365847365874387458437564327"

    result = solution.multiply(num1, num2)

    print(f"The product of {num1} and {num2} is: {result}")


start_time = time.time()
# Run your algorithm here
end_time = time.time()

execution_time = end_time - start_time
print(f"Execution Time: {execution_time} seconds")