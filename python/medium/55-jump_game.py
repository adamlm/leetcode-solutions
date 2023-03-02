class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reach = 0

        for idx, jump in enumerate(nums[:-1]):
            if idx <= max_reach:
                max_reach = max(max_reach, idx + jump)
            else:
                return False

        return max_reach >= len(nums) - 1

