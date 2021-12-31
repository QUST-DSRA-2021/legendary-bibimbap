class Solution:
    def arrangeCoins(self, m: int) -> int:
        res, k = 0, 0
        while m >= k:
            res += 1
            m -= k
            k += 1
        return res - 1

