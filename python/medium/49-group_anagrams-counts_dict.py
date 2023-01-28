from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        for s in strs:
            groups[char_counts(s)].append(s)

        return [val for val in groups.values()]


def char_counts(s) -> tuple:
    counts = [0] * 26
    for c in s:
        counts[int(ord(c) - ord('a'))] += 1

    return tuple(counts)

