class Solution:
    def missingNumber(self, ar: List[int]) -> int:
        flags = [False] * (len(ar) + 1)
        for each in ar:
            flags[each] = True
        for k in range(1, len(ar) + 1):
            if not flags[k]:
                return k
