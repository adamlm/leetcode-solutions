class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'

        partial_products = []
        total = '0'

        for idx, digit2 in enumerate(reversed(num2)):
            partial_product = ''
            carry = 0
            for digit1 in reversed(num1):
                product = int(digit1) * int(digit2) + carry
                carry = product // 10
                remainder = product % 10
                partial_product += str(remainder)

            if carry:
                partial_product += str(carry)

            partial_products.append(partial_product[::-1] + '0' * idx)

        for partial_product in partial_products:
            total = add_strings(total, partial_product)

        return total


def add_strings(num1, num2):
    idx_1 = len(num1) - 1
    idx_2 = len(num2) - 1

    total = ''
    carry = 0
    while idx_1 >= 0 or idx_2 >= 0:
        digit_sum = 0
        if idx_1 >= 0:
            digit_sum += int(num1[idx_1])
        if idx_2 >= 0:
            digit_sum += int(num2[idx_2])

        digit_sum += carry

        carry = digit_sum // 10
        remainder = digit_sum % 10
        total += str(remainder)

        idx_1 -= 1
        idx_2 -= 1

    if carry:
        total += str(carry)

    return total[::-1]

