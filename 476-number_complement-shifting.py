import math

class Solution:
    def findComplement(self, num: int) -> int:
        stack = 0
        bits = 0

        while num > 0:
            stack <<= 1
            stack |= (num & 1) ^ 1
            num >>= 1
            bits += 1

        result = 0
        for _ in range(bits):
            result <<= 1
            result |= (stack & 1)
            stack >>= 1

        return result

