class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.searchInsertRecurse(nums, 0, target)
    
    def searchInsertRecurse(self, nums: List[int], start: int, target: int) -> int:
        if not nums:
            return 0
            
        mid = len(nums) // 2
        
        if nums[mid] == target:
            return start + mid
        
        if nums[mid] > target:
            if mid == 0:
                return start
            
            return self.searchInsertRecurse(nums[:mid], start, target)
            
        if mid == len(nums) - 1:
            return start + len(nums)
        
        return self.searchInsertRecurse(nums[mid + 1:], start + mid + 1, target)
        
