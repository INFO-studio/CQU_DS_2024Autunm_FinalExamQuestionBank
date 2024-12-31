/***********
 * Background
 * Special for beginners, ^_^
 * 
 * Description
 * 输入一棵二叉树的先序和中序遍历序列，输出其后序遍历序列。
 * 
 * Format
 * Input
 * 输入共两行。
 * 
 * 第一行一个字符串，表示树的先序遍历；
 * 
 * 第二行一个字符串，表示树的中序遍历。
 * 
 * 树的结点一律用小写字母表示，长度小于 50。
 * 
 * Output
 * 输出仅一行，表示树的后序遍历序列。
 * 
 * Samples
 * 样例输入
 * abdec
 * dbeac
 * 样例输出
 * debca
 * Limitation
 * 1s, 1024KiB for each test case.
 ***********/

#include <iostream>
#include <string>  // 包含string

using namespace std;

void solve(string pre, string in, int pre_target, int in_begin, int in_len) {  // 递归求解
    if (in_len == 0) {  // 如果in_len为0
        return;  // 返回
    } else if (in_len == 1) {  // 如果in_len为1
        cout << pre[pre_target];  // 输出pre[pre_target]
    } else {  // 否则
        for (int i = 0; i < in_len; i++) {  // 遍历i从0到in_len-1
            if (in[in_begin + i] == pre[pre_target]) {  // 如果in[in_begin + i]等于pre[pre_target]，即找到根节点
                solve(pre, in, pre_target + 1, in_begin, i);  // 递归求解前半部分
                solve(pre, in, pre_target + i + 1, in_begin + i + 1, in_len - i - 1);  // 递归求解后半部分
                cout << pre[pre_target];  // 输出根节点
            }
        }
    }
}

int main() {
    string pre, in;
    cin >> pre >> in;
    solve(pre, in, 0, 0, in.size());
}