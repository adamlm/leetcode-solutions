class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        result = ''
        count = 0
        for char in reversed(s):
            if char != '-':
                if count == k:
                    result += '-'
                    count = 0

                result += char.upper()
                count += 1

        return result[::-1]

