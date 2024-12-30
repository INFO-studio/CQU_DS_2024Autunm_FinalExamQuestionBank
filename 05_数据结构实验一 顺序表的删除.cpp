/***********
 * 以顺序表作存储结构，实现线性表的创建、删除。
 * 
 * 顺序表的类型描述
 * 
 * #define MAXSIZE 10     // MAXSIZE为最大数据元素数目
 * typedef int ElemType;
 * typedef struct
 * {  ElemType  *elem;
 *    int length; 
 * } SqList;
 * 输入格式:
 * 输入分三行
 * 
 * 第一行 元素个数
 * 第二行 元素的值。元素间以空格分隔。
 * 第三行 待删除元素位置
 * 具体格式参看输入样例
 * 
 * 输出格式:
 * 输出分两行
 * 
 * 第一行 删除前的线性表
 * 
 * 第二行 删除后的线性表。如因删除位置错误失败，输出Delete position error!。
 * 
 * 具体格式参看输出样例
 * 
 * 输入样例:
 * 5
 * 2 4 6 8 10
 * 3
 * 输出样例:
 * Before:(2,4,6,8,10)
 * After:(2,4,8,10)
 * 输入样例:
 * 5
 * 2 4 6 8 10
 * 6
 * 输出样例:
 * Before:(2,4,6,8,10)
 * Delete position error!
 ***********/

#include <iostream>
#include <vector>  // 包含vector

using namespace std;

int main() {
    int n;  // 定义n
    cin >> n;  // 输入n
    vector<int> sqlist(n);  // 定义sqlist
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        cin >> sqlist[i];  // 输入sqlist[i]
    }
    cout << "Before:(";  // 输出前导Before:(
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        cout << sqlist[i];  // 输出sqlist[i]
        if (i != n - 1) {  // 如果不是最后一个元素
            cout << ',';  // 输出逗号
        }
    }
    cout << ')' << endl;  // 输出尾随)
    int d;  // 定义删除元素下标d
    cin >> d;  // 输入d
    d--;  // d减1，因为下标从0开始
    if (d < 0 || d >= n) {  // 如果d小于0或者d大于等于n
        cout << "Delete position error!";  // 输出Delete position error!
    } else {  // 否则
        sqlist.erase(sqlist.begin() + d);  // 删除sqlist中下标为d的元素
        cout << "After:(";  // 输出前导After:(
        for (int i = 0; i < n - 1; i++) {  // 遍历i从0到n-2
            cout << sqlist[i];  // 输出sqlist[i]
            if (i != n - 2) {  // 如果不是最后一个元素
                cout << ',';  // 输出逗号
            }
        }
        cout << ')';  // 输出尾随)
    }
}