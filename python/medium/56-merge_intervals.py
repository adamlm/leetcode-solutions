class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda i: i[0])
        result = [intervals[0]]

        for int_start, int_stop in intervals[1:]:
            if int_start <= result[-1][1]:
                result[-1][1] = max(result[-1][1], int_stop)
            else:
                result.append([int_start, int_stop])

        return result

