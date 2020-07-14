class Solution:
    def isPalindrome(self, x: int) -> bool:
        rev = 0
        
        if (x < 10 and x >= 0):
            return True
        elif (x < 0 or x % 10 == 0):
            return False
        
        while x > 0:
            digit = x % 10
            x //= 10
            rev = rev * 10 + digit
            
            if rev == x or (x >= 10 and rev == (x // 10)):
                return True
        
        return False
