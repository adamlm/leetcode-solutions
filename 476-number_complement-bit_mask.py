import math

class Solution:
    def findComplement(self, num: int) -> int:
        if not (num & (num - 1)):
            return num - 1

        mask_width = math.ceil(math.log(num, 2))
        mask = 2 ** mask_width - 1

        return num ^ mask

