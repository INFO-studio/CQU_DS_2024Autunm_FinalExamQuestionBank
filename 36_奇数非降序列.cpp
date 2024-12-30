/***********
 * 给定一个长度为N（不大于500）的正整数序列，请将其中的所有奇数取出，并按升序输出。
 * 
 * 输入格式:
 * 第1行为 N；
 * 
 * 第2行为 N 个正整数，其间用空格间隔。
 * 
 * 输出格式:
 * 增序输出的奇数序列，数据之间以逗号间隔。数据保证至少有一个奇数。
 * 
 * 输入样例:
 * 10
 * 3 2 6 5 4 9 8 7 10 1
 * 输出样例:
 * 1,3,5,7,9
 ***********/

#include <iostream>
#include <vector>
#include <algorithm>  // 包含sort函数

using namespace std;

int main() {
    int n;  // 定义n
    cin >> n;  // 输入n
    vector<int> v;  // 定义v
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        int ele;  // 定义ele
        cin >> ele;  // 输入ele
        if (ele % 2 != 0) {  // 如果ele是奇数
            v.push_back(ele);  // 将ele加入v
        }
    }
    sort(v.begin(), v.end());  // 对v进行升序排序
    for (int i = 0; i < int(v.size()); i++) {  // 遍历i从0到v.size()-1
        cout << v[i];  // 输出v[i]
        if (i != int(v.size()) - 1) {  // 如果不是最后一个元素
            cout << ',';  // 输出逗号
        }
    }
}