#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

int a[1005]; // 输入数据

int max_value,max_pos; // 全局保存的最大值和最大值对应的下标

void f(int index);

int main(){
    int m;
    cin >> m;
    for (int k = 1; k <= m; k++)
        cin >> a[k];
    f(m); // 用递归的方式找出最大值和最大值对应的数组下标
    cout << max_value << ' ' << max_pos << endl;
}

void f(int index) {
    if (index == 1) {
        max_value = a[index];
        max_pos = index;
        return;
    } else {
        f(index - 1);
        /* 继续完成缺失代码 */
        if (a[index] > max_value) {
            max_value = a[index];
            max_pos = index;
        }
        return;
    }
}
