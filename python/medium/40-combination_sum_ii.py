class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []
        combo = []

        helper(sorted(candidates), target, results, combo)
        
        return results


def helper(candidates, target, results, combo):
    for idx, num in enumerate(candidates):
        if idx > 0 and candidates[idx - 1] == num:
            continue

        diff = target - num

        if diff < 0:
            break
        elif diff == 0:
            if combo + [num] not in results:
                results.append(combo + [num])
            break
        
        helper(candidates[idx + 1:], diff, results, combo + [num])

