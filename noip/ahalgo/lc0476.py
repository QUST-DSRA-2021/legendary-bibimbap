class Solution:
    def findComplement(self, num: int) -> int:
        return eval("0b%s" % bin(num)[ 2 : ].replace("0", "-")
                                            .replace("1", "0")
                                            .replace("-", "1"))
