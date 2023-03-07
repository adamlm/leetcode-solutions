import math


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        permutations = [nums.copy()]

        for _ in range(math.factorial(len(nums))):
            for i in range(len(nums) - 2, -1, -1):
                if nums[i] < nums[i + 1]:
                    next_smallest = 11
                    next_idx = i + 1

                    for j in range(len(nums) - 1, i, -1):
                        if nums[i] < nums[j] < next_smallest:
                            next_smallest = nums[j]
                            next_idx = j

                    tmp = nums[i]
                    nums[i] = nums[next_idx]
                    nums[next_idx] = tmp
                    nums[i + 1:] = reversed(nums[i + 1:])
                    permutations.append(nums.copy())
                    break

        return permutations

