class Solution:
    def longestSubsequence(self, arr: List[int], dif: int) -> int:
        dp = defaultdict(int)
        for u in arr:
            dp[u] = dp[u - dif] + 1
        return max(dp.values())
