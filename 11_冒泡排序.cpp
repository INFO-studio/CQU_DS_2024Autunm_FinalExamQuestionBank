/***********
 * 本题目要求读入N个整数，采用冒泡排序（上升法，即每轮得到一个最小值）进行排序，输出的排序结果只是前三趟。
 * 
 * 输入格式:
 * 输入不超过100的正整数N和N个整数（空格分隔）。
 * 
 * 输出格式:
 * 输出前三趟冒泡排序结果，空格分隔。
 * 
 * 为简便起见，最后一个元素后也有一个空格。最后一行也有换行符。
 * 
 * 输入样例:
 * 5
 * 2 5 4 1 3
 * 输出样例:
 * 1 2 5 4 3 
 * 1 2 3 5 4 
 * 1 2 3 4 5 
 * 
 ***********/

#include <iostream>
#include <vector>  // 包含vector

using namespace std;

int main() {
    int n;  // 定义n
    cin >> n;  // 输入n
    vector<int> v(n);  // 定义大小为n的vector v
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        cin >> v[i];  // 输入v[i]
    }
    for (int i = 0; i < 3 && i < n - 1; i++) {  // 遍历i从0到2，且i小于n-1
        for (int j = n - 1; j > i; j--) {  // 遍历j从n-1到i+1
            if (v[j - 1] > v[j]) {  // 如果v[j - 1]大于v[j]
                swap(v[j - 1], v[j]);  // 交换v[j - 1]和v[j]
            }
        }
        for (int j = 0; j < n; j++) {  // 遍历j从0到n-1
            cout << v[j] << ' ';  // 输出v[j]
        }
        cout << endl;  // 换行
    }
}