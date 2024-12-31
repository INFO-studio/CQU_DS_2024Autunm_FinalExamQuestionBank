/***********
 * 插入排序是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 * 
 * 输入格式:
 * 输入在第1行中给出N（1<N≤100），在第2行中给出N个待排序的整数，数字间以空格分隔，并保证数字没有重复的出现。
 * 
 * 输出格式:
 * 给出插入排序每一遍后的中间结果数列，数字间以空格分隔，但末尾不得有多余空格。
 * 
 * 输入样例:
 * 7
 * 4 5 7 6 3 2 1
 * 输出样例:
 * 4 5 7 6 3 2 1
 * 4 5 7 6 3 2 1
 * 4 5 6 7 3 2 1
 * 3 4 5 6 7 2 1
 * 2 3 4 5 6 7 1
 * 1 2 3 4 5 6 7
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
    for (int i = 1; i < n; i++) {  // 遍历i从1到n-1
        for (int j = 0; j < i; j++) {  // 遍历j从0到i-1
            if (v[i] < v[j]) {  // 如果v[i]小于v[j]
                swap(v[i], v[j]);  // 交换v[i]和v[j]
            }
        }
        for (int j = 0; j < n; j++) {  // 遍历j从0到n-1
            cout << v[j];  // 输出v[j]
            if (j != n - 1) {  // 如果j不等于n-1
                cout << ' ';  // 输出空格
            }
        }
        cout << endl;  // 换行
    }
}