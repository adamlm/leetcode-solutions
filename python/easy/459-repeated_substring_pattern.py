class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for stride in range(1, len(s)):
            substring = s[:stride]

            if len(s) % stride != 0:
                continue

            for start in range(0, len(s), stride):
                if s[start:start + stride] != substring:
                    break
            else:
                return True

        return False

