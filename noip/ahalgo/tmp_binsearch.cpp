#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

class Binsearch {
public:
    int sln1(vector <int> arr, int target) {
        /**
         * 二分查找的最基础和最基本的形式。这是一个标准的二分查找方案，大多数高中或大学会在他们第一次教学生计算机科学时使用。该方案用于查找可以*通过访问数组中的单个索引*来确定的元素或条件。
         * Key Attributes:
         * * 二分查找的最基础和最基本的形式。
         * * 查找条件可以在不与元素的两侧进行比较的情况下确定（或使用它周围的特定元素）。
         * * **不需要后处理。**因为每一步中，你都在检查是否找到了元素。如果到达末尾，则知道未找到该元素。
         * Key Operations:
         * * Initial Conditions: `lbound = 0, rbound = length - 1`
         * * Ender: `lbound > rbound`
         * * Search Left: `rbound = mid - 1`
         * * Search Right: `lbound = mid + 1`
         */
        sort(arr.begin(), arr.end());
        int arrlen = arr.size();
        if (arrlen != 0) {
            int lbound = 0,
                rbound = arrlen - 1;
            while (lbound <= rbound) {
                // To Prevent `(lbound + rbound)` Overflow
                int mid = (lbound + rbound) >> 1; // Also `lbound + (rbound - lbound) >> 1` is Okay
                if (arr[mid] == target)
                    return mid;
                else if (arr[mid] < target)
                    lbound = mid + 1;
                else
                    rbound = mid - 1;
            }
        }
        return (-1);
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
