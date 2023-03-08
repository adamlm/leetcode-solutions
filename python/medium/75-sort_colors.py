class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        twos = len(nums) - 1
        for num in reversed(nums):
            if num == 2:
                twos -= 1
            else:
                break

        idx = 0
        while idx < twos:
            while nums[twos] == 2:
                twos -= 1

            if idx >= twos:
                break

            if nums[idx] == 2:
                swap(nums, idx, twos)
                twos -= 1

            idx += 1

        zeros = 0
        for num in nums:
            if num == 0:
                zeros += 1
            else:
                break

        idx = len(nums) - 1
        while idx > zeros:
            while nums[zeros] == 0:
                zeros += 1

            if idx <= zeros:
                break

            if nums[idx] == 0:
                swap(nums, idx, zeros)
                zeros += 1

            idx -= 1


def swap(nums, a, b) -> None:
    tmp = nums[a]
    nums[a] = nums[b]
    nums[b] = tmp

