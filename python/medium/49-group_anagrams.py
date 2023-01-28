class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        tups = sorted([(sorted(s), i) for i, s in enumerate(strs)], key=lambda t: t[0])
        result = [[strs[tups[0][1]]]]
        key = tups[0][0]

        for t in tups[1:]:
            if len(t[0]) == len(key) and t[0] == key:
                result[-1].append(strs[t[1]])
            else:
                result.append([strs[t[1]]])
                key = t[0]

        return result

