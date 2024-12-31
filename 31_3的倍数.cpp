/***********
 * 给你一个正整数，请你判断它是不是3的倍数？
 * 
 * 输入格式:
 * 输入数据有一个T(T<=50)，代表有T组数据
 * 
 * 对于每组数据，一个整数n  (1<=n<=1e1000)  注意数据范围
 * 
 * 这个题需要知道一个数能被3整除的特殊性质，即每一位数字的和能够被3整除，该数字就能被3整除。
 * 
 * 输出格式:
 * 对于每组数据，输出一行“YES”或“NO”（不包括引号），代表这个数是或不是3的倍数
 * 
 * 输入样例:
 * 在这里给出一组输入。例如：
 * 
 * 2
 * 33332
 * 123
 * 输出样例:
 * 在这里给出相应的输出。例如：
 * 
 * NO
 * YES
 ***********/

#include <iostream>
#include <string>  // 包含string

using namespace std;

int main() {
    int n;  // 定义n
    cin >> n;  // 输入n
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        string num;  // 定义num
        cin >> num;  // 输入num
        int sum = 0;  // 定义sum为num的各位数字之和
        for (char j: num) {  // 遍历num的各位数字
            sum += j - '0';  // 将各位数字相加
        }
        if (sum % 3 == 0) {  // 如果sum能被3整除
            cout << "YES" << endl;  // 输出YES
        } else {  // 否则
            cout << "NO" << endl;  // 输出NO
        }
    }
}