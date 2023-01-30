class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'

        s = ''
        negative = num < 0
        num = abs(num)

        while num > 0:
            s += str(num % 7)
            num //= 7

        if negative:
            s += '-'

        return s[::-1]

