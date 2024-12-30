/***********
 * 实现一个队列，队列初始为空，支持四种操作：
 * 
 * 1.push x – 向队尾插入一个数 x；
 * 2.pop – 从队头弹出一个数；
 * 3.empty – 判断队列是否为空；
 * 4.query – 查询队头元素。
 * 现在要对队列进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。
 * 
 * 输入格式:
 * 第一行包含整数 M，表示操作次数。
 * 
 * 接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。
 * 
 * 输出格式:
 * 对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。
 * 
 * 其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示队头元素的值。
 * 
 * 数据范围：
 * 1≤M≤100000,
 * 1≤x≤10 
 * 9
 *  ,
 * 所有操作保证合法。
 * 
 * 输入样例:
 * 在这里给出一组输入。例如：
 * 
 * 10
 * push 6
 * empty
 * query
 * pop
 * empty
 * push 3
 * push 4
 * pop
 * query
 * push 6
 * 输出样例:
 * 在这里给出相应的输出。例如：
 * 
 * NO
 * 6
 * YES
 * 4
 ***********/

#include <iostream>
#include <string>  // 包含string
#include <queue>  // 包含queue

using namespace std;

int main() {
    int n;  // 定义n
    cin >> n;  // 输入n
    queue<int> q;  // 定义队列q
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        string opt;  // 定义操作opt
        cin >> opt;  // 输入opt
        if (opt == "push") {  // 如果opt是push
            int ele;  // 定义ele
            cin >> ele;  // 输入ele
            q.push(ele);  // 将ele加入q
        } else if (opt == "pop") {  // 如果opt是pop
            q.pop();  // 弹出队头元素
        } else if (opt == "empty") {  // 如果opt是empty
            cout << (q.empty() ? "YES" : "NO") << endl;  // 输出q是否为空
        } else if (opt == "query") {  // 如果opt是query
            cout << q.front() << endl;  // 输出队头元素
        }
    }
}