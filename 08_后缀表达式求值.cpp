/***********
 * 后缀表达式，又称逆波兰式，指的是不包含括号，运算符放在两个运算对象的后面，所有的计算按运算符出现的顺序，严格从左向右进行。
 * 
 * 运用后缀表达式进行计算的具体做法：
 * 
 * 建立一个操作数栈S。然后从左到右读表达式，如果读到操作数就将它压入栈S中，如果读到n元运算符(即需要参数个数为n的运算符)则取出由栈顶向下的n项操作数进行运算，再将运算的结果代替原栈顶的n项压入栈中。重复上面过程，如果后缀表达式读完且栈中只剩一个操作数，则该数就是运算结果；如果后缀表达式读完但是栈中操作数多于一个，则后缀表达式错误；如果栈中操作数只剩一个，但是后缀表达式还未读完且当前运算符为双元操作符，则后缀表达式同样错误。
 * 
 * 输入格式:
 * 在一行中输入一个以#号结束的非空后缀式，#不属于表达式的一部分，操作数和运算符都以空格分隔，运算数为绝对值不超过100的整数，运算符仅有+、-、*、/ 四种。
 * 
 * 输出格式:
 * 输出后缀式计算结果，所有的计算都只取结果的整数部分。题目保证计算的中间和最后结果的绝对值都不超过1e9。
 * 
 * 如果执行除法时出现分母为零的非法操作，则在一行中输出：Error: X/0，X是当时的分子。
 * 
 * 如果后缀表达式中运算符多了或者少了，则在一行中输出：Expression Error: X，X是当时栈顶元素。
 * 
 * 输入样例1:
 * 5 -2 + 3 * #
 * 输出样例1:
 * 9
 * 输入样例2:
 * 5 -2 2 + / #
 * 输出样例2:
 * Error: 5/0
 * 输入样例3:
 * 5 -1 3 + / - * #
 * 输出样例3:
 * Expression Error: 2
 ***********/

#include <iostream>
#include <string>  // 包含string
#include <stack>  // 包含stack

using namespace std;

int main() {
    stack<int> s;  // 定义栈s
    string now;  // 定义now
    while (true) {  // 无限循环
        cin >> now;  // 输入now
        if (now == "#") {  // 如果now为#
            break;  // 退出循环
        }
        if (now == "+" || now == "-" || now == "*" || now == "/") {  // 如果now为运算符
            if (s.size() < 2) {  // 如果栈中元素少于2个
                cout << "Expression Error: " << s.top();  // 输出Expression Error: 栈顶元素
                return 0;  // 结束程序
            }
            int x = s.top(); s.pop();  // 取出栈顶元素
            int y = s.top(); s.pop();  // 取出栈顶元素
            if (now == "+") {  // 如果now为+
                s.push(y + x);  // 将y + x压入栈
            } else if (now == "-") {  // 如果now为-
                s.push(y - x);  // 将y - x压入栈
            } else if (now == "*") {  // 如果now为*
                s.push(y * x);  // 将y * x压入栈
            } else if (now == "/") {  // 如果now为/
                if (x == 0) {  // 如果x为0
                    cout << "Error: " << y << '/' << x;  // 输出Error: y/x
                    return 0;  // 结束程序
                }
                s.push(y / x);  // 将y / x压入栈
            }
        } else {  // 否则
            int num = stoi(now);  // 将now转换为整数
            s.push(num);  // 将num压入栈
        }
    }
    if (s.size() == 1) {  // 如果栈中元素只剩一个
        cout << s.top();  // 输出栈顶元素
    } else {  // 否则
        cout << "Expression Error: " << s.top();  // 输出Expression Error: 栈顶元素
    }
}