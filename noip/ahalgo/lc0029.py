class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MIN, INT_MAX = -0x80000000, 0x7fffffff

        # 审察被除数为负数下限的情况
        if dividend == INT_MIN:
            if divisor == 1:
                return INT_MIN
            if divisor == -1:
                return INT_MAX

        # 审察除数为负数下限的情况
        if divisor == INT_MIN:
            return 0 if dividend != INT_MIN else 1
        # 审察被除数为零的情况
        if dividend == 0:
            return 0

        # 其他情况则使用二分查找
        rev = False
        if dividend > 0:
            dividend *= (-1)
            rev = not rev
        if divisor > 0:
            divisor *= (-1)
            rev = not rev

        # 快速乘法
        def fastadd(y: int, z: int, x: int) -> bool:
            """
            x, y < 0, z > 0
            需判断 z * y >= x 是否成立
            """
            res, add = 0, y
            while z > 0:
                if (z & 1) == 1:
                    if res < x - add:
                        return False
                    res += add
                if z != 1:
                    if add < x - add:
                        return False
                    add <<= 1
                z >>= 1
            return True

        lbound, rbound, res = 1, INT_MAX, 0
        while lbound <= rbound:
            mid = (lbound + rbound) >> 1
            if fastadd(divisor, mid, dividend):
                res = mid
                if mid == INT_MAX:
                    break
                lbound = mid + 1
            else:
                rbound = mid - 1

        return -res if rev else res
