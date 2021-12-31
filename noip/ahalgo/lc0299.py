class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        num_bulls, err1, err2 = 0, [0] * 10, [0] * 10
        for k in range(len(secret)):
            if secret[k] != guess[k]:
                err1[int(secret[k])] += 1
                err2[int(guess[k])] += 1
            else:
                num_bulls += 1
        return "%sA%sB" % (num_bulls, sum([ min(err1[k], err2[k]) for k in range(10) ]))
