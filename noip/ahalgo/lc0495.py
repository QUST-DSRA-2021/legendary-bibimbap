class Solution:
    def findPoisonedDuration(self, arr_t: List[int], drt: int) -> int:
        return sum([ min(arr_t[k + 1] - arr_t[k], drt) for k in range(len(arr_t) - 1) ]) + drt
