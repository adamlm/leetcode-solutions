import math


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        length = math.ceil(math.sqrt(area))
        width = math.floor(math.sqrt(area))

        while True:
            a = length * width
            if a == area:
                return [length, width]

            if a > area and width > 1:
                width -= 1
            else:
                length += 1

