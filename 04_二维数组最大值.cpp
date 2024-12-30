/***********
 * 本题目要求读入M(最大为10)行N（最大为15）列个元素，找出其中最大的元素，并输出其行列值。
 * 
 * 输入格式:
 * 输入在第一行中给出行数m和列数n。
 * 接下来输入m*n个整数。
 * 
 * 输出格式:
 * 输出最大值的行号,列号,值。
 * 
 * 输入样例:
 * 2 3
 * 1 2 3
 * 4 5 6
 * 输出样例:
 * 最大值为1行2列的6
 * 
 * 1,2,6
 ***********/

#include <iostream>
#include <climits>  // 包含INT_MIN

using namespace std;

int main() {
    int m, n;  // 定义m和n
    cin >> m >> n;  // 输入m和n
    int max = INT_MIN, x, y;  // 定义max为INT_MIN，x和y
    for (int i = 0; i < m; i++) {  // 行遍历
        for (int j = 0; j < n; j++) {  // 列遍历
            int ele;  // 定义ele
            cin >> ele;  // 输入ele
            if (ele > max) {  // 如果ele大于max
                max = ele;  // 更新max
                x = i;  // 更新x
                y = j;  // 更新y
            }
        }
    }
    cout << x << ',' << y << ',' << max;  // 输出x，y和max
}