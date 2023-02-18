class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return binary_search(nums, 0, len(nums), target)


def binary_search(nums, left, right, target):
    if left >= right:
        return -1

    middle = (left + right) // 2

    if nums[middle] == target:
        return middle

    if nums[left] < nums[middle]:
        if nums[left] <= target < nums[middle]:
            return binary_search(nums, left, middle, target)
    else:
        if target >= nums[left] or target < nums[middle]:
            return binary_search(nums, left, middle, target)

    return binary_search(nums, middle + 1, right, target)

