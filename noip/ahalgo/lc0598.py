class Solution:
    def maxCount(self, m: int, n: int, opt: List[List[int]]) -> int:
        min_x, min_y = m, n
        for a, b in opt:
            min_x = min(a, min_x)
            min_y = min(b, min_y)
        return min_x * min_y
