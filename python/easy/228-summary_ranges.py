class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        elif len(nums) < 2:
            return [str(nums[0])]

        ranges = [str(nums[0])]
        prev = nums[0]
        expected = prev + 1

        for num in nums[1:]:
            if num == expected:
                prev = num
                expected = prev + 1
                continue
            
            if ranges[-1] != str(prev):
                ranges[-1] += f'->{prev}'

            ranges.append(str(num))
            prev = num
            expected = prev + 1

        if ranges[-1] != str(prev):
                ranges[-1] += f'->{prev}'

        return ranges

