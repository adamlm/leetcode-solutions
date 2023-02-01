class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if decreasing_order(nums):
            nums.reverse()
            return

        for i in reversed(range(len(nums) - 1)):
            if nums[i] < nums[i + 1]:
                next_smallest = 101
                jdx = i
                for j in range(i, len(nums)):
                    if nums[j] > nums[i] and nums[j] <= next_smallest:
                        next_smallest = nums[j]
                        jdx = j
                tmp = nums[i]
                nums[i] = next_smallest
                nums[jdx] = tmp
                rev(i + 1, nums)
                return


def rev(idx: int, nums: List[int]) -> None:
    l = idx
    r = len(nums) - 1
    while l < r:
        tmp = nums[l]
        nums[l] = nums[r]
        nums[r] = tmp
        l += 1
        r -= 1


def decreasing_order(nums: List[int]) -> bool:
    for n, m in zip(nums[:-1], nums[1:]):
        if not n >= m:
            return False

    return True

