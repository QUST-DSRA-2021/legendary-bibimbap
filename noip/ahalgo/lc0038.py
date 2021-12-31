class Solution:
    def countAndSay(self, m: int) -> str:
        prev = "1"
        for k in range(m - 1):
            curr = ""
            pos = 0
            start = 0

            while pos < len(prev):
                while pos < len(prev) and prev[pos] == prev[start]:
                    pos += 1
                curr += str(pos - start) + prev[start]
                start = pos
            prev = curr

        return prev

