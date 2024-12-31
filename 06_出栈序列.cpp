/***********
 * 堆栈是一种经典的后进先出的线性结构，相关的操作主要有“入栈”（在堆栈顶插入一个元素）和“出栈”（将栈顶元素返回并从堆栈中删除）。我们用P表示入栈操作，用O表示出栈操作。给定一个入栈序列和一个结果序列，假如入栈过程中允许出栈，请判断结果序列是否是一个合法的出栈序列。例如入栈序列为1,2,3,4,5，则3,4,5,2,1是一个合法的出栈序列，对应的操作序列为PPPOPOPOOO，而3,4,5,1,2不是一个合法的出栈序列，因为子序列3,4,5可以经过PPPOPOPO操作序列得到，但是此时栈顶元素为2，无法与结果序列剩余子序列匹配，则判断结果不合法，此时堆栈里面剩余序列从栈底到栈顶依次为2,1。
 * 
 * 输入格式:
 * 输入为两行，第一行为入栈序列，第二行为结果序列，两个序列都是长度不超过10仅有0-9组成的字符串。
 * 
 * 输出格式:
 * 输出为两行，如果结果序列是合法的出栈序列，则第一行输出“right”，第二行输出入栈出栈操作的顺序序列，否则，第一行输出“wrong”，第二行按照从底到顶的顺序输出无法继续进行入栈出栈操作时堆栈里面的剩余元素。
 * 
 * 输入样例1:
 * 12345
 * 34521
 * 输出样例1:
 * right
 * PPPOPOPOOO
 * 输入样例2:
 * 12345
 * 34512
 * 输出样例2:
 * wrong
 * 12
 ***********/

#include <iostream>
#include <string>  // 包含string
#include <stack>  // 包含stack
#include <algorithm>  // 包含reverse

using namespace std;

int main() {
    string in, out;  // 定义入栈序列和结果序列
    cin >> in >> out;  // 输入in和out
    stack<char> s;  // 定义栈s
    string ans = "";  // 定义ans，表示操作序列
    int nowin = 0;  // 定义nowin，表示当前入栈序列的位置
    for (char i: out) {  // 遍历i从out的第一个元素到最后一个元素
        if (!s.empty() && i == s.top()) {  // 如果栈不为空且i等于栈顶元素
            s.pop();  // 出栈
            ans += 'O';  // 输出O
        } else if (in[nowin] == i) {  // 如果当前入栈序列的元素等于i，即直接入栈+出栈
            nowin++;  // nowin加1
            ans += 'P';  // 输出P
            ans += 'O';  // 输出O
        } else {  // 否则
            while (nowin < int(in.size()) && in[nowin] != i) {  // 当nowin小于in的长度且当前入栈序列的元素不等于i
                s.push(in[nowin]);  // 入栈
                nowin++;  // nowin加1
                ans += 'P';  // 输出P
            }
            if (in[nowin] == i) {  // 如果当前入栈序列的元素等于i，即直接入栈+出栈
                nowin++;  // nowin加1
                ans += 'P';  // 输出P
                ans += 'O';  // 输出O
            } else {  // 否则
                cout << "wrong" << endl;  // 输出wrong
                ans = "";  // 清空ans
                while(!s.empty()) {  // 将栈中剩余元素填入ans
                    ans += s.top();
                    s.pop();
                }
                reverse(ans.begin(), ans.end());  // 反转ans
                cout << ans;  // 输出ans
                return 0;
            }
        }
    }
    cout << "right" << endl << ans;  // 输出right和ans
}