class Solution:
    def trap(self, h: List[int]) -> int:
        m = len(h)
        if m <= 2:
            return 0
        else:
            max_left = [h[0]] + [0] * (m - 1)
            max_right = [0] * (m - 1) + [h[-1]]
            for k in range(1, m):
                max_left[k] = max(max_left[k - 1], h[k])
            for k in range(m - 2, -1, -1):
                max_right[k] = max(max_right[k + 1], h[k])
            return sum([ (min(max_left[k], max_right[k]) - h[k]) for k in range(m) ])
