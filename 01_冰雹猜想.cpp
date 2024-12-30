/***********
 * 冰雹猜想的内容是：任何一个大于1的整数n，按照n为偶数则除等2，n为奇数则乘3后再加1的规则不断变化，最终都可以变化为1。
 * 
 * 例如，n等于20，变化过程为：20、10、5、16、8、4、2、1。编写程序，用户输入n，输出变化过程以及变化的次数。
 * 
 * 输入格式:
 * 输入一个整数n。
 * 
 * 输出格式:
 * 输出猜想的过程及变化次数。
 * 
 * 输入样例:
 * 20
 * 
 * 输出样例:
 * 20 10 5 16 8 4 2 1
 * count = 8
 ***********/

#include <iostream>

using namespace std;

int main() {
    int n;  // 定义n
    cin >> n;  // 输入n
    int count = 1;  // 计数器
    while (n != 1) {  // 当n不等于1时
        cout << n << " ";  // 输出n
        if (n % 2 == 0) {  // 如果n是偶数
            n /= 2;  // n除以2
        } else {  // 如果n是奇数
            n = 3 * n + 1;  // n乘以3加1
        }
        count++;  // 计数器加1
    }
    cout << 1 << endl << "count = " << count << endl;  // 输出尾随1和count
}