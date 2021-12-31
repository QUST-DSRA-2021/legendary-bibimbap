class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        m = len(num)
        ans = []

        def backtrack(expr: List[str], k: int, res: int, mul: int):
            if k == m:
                if res == target:
                    ans.append("".join(expr))
                return
            signIndex = len(expr)
            if k > 0:
                expr.append("")  # 占位，下面填充符号
            val = 0
            for l in range(k, m):  # 枚举截取的数字长度（取多少位）
                if l > k and num[k] == "0":  # 数字可以是单个 0 但不能有前导零
                    break
                val = val * 10 + int(num[l])
                expr.append(num[l])
                if k == 0:  # 表达式开头不能添加符号
                    backtrack(expr, l + 1, val, val)
                else:  # 枚举符号
                    expr[signIndex] = "+"; backtrack(expr, l + 1, res + val, val)
                    expr[signIndex] = "-"; backtrack(expr, l + 1, res - val, -val)
                    expr[signIndex] = "*"; backtrack(expr, l + 1, res - mul + mul * val, mul * val)
            del expr[signIndex:]

        backtrack([], 0, 0, 0)
        return ans
