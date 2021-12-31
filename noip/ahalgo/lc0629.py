class Solution:
    def kInversePairs(self, m: int, i: int) -> int:
        mod = 10**9 + 7
        
        f = [1] + [0] * i
        for k in range(m):
            g = [0] * (i + 1)
            for l in range(i + 1):
                g[l] = (g[l - 1] if l - 1 >= 0 else 0) - (f[l - (k + 1)] if l - (k + 1) >= 0 else 0) + f[l]
                g[l] %= mod
            f = g
        
        return f[i]
