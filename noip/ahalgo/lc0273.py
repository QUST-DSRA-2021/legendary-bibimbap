class Solution:
    class Constants(object):
        singles = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        teens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        thousands = ["", "Thousand", "Million", "Billion"]

    def numberToWords(self, num: int) -> str:
        if num != 0:

            def recursion(num: int) -> str:
                res = ""
                if num == 0:
                    return res
                elif num < 10:
                    res += Solution.Constants.singles[num] + " "
                elif num < 20:
                    res += Solution.Constants.teens[num - 10] + " "
                elif num < 100:
                    res += Solution.Constants.tens[num // 10] + " " + recursion(num % 10)
                else:
                    res += Solution.Constants.singles[num // 100] + " Hundred " + recursion(num % 100)
                return res

            res = ""
            unit = int(1E+9)
            for k in range(4):
                cur_num = num // unit
                if cur_num:
                    num -= cur_num * unit
                    res += recursion(cur_num) + Solution.Constants.thousands[3 - k] + " "
                unit //= 1000
            return res.strip()

        else:
            return "Zero"
