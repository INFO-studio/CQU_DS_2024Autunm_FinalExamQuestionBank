/***********
 * 输出给定图的邻接表。
 * 
 * 输入格式:
 * 输入第一行给出三个正整数，分别表示无向图的节点数N（1<N≤10）、边数M（≤50）和有向或无向标志S（1表示有向图，0表示无向图）。
 * 随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号（编号范围1~N）。
 * 
 * 输出格式:
 * 输出图的邻接表，从第0行开始按顺序输出，共输出N行，具体样式见输出样例。冒号前后无空格，每个元素间有一个空格，末尾均有一空格。
 * 由于图的存储是不唯一的，为了使得输出具有唯一的结果，我们约定以表头插入法构造邻接表。
 * 
 * 输入样例:
 * 6 8 0 
 * 1 2
 * 2 3 
 * 3 4 
 * 4 5 
 * 5 6 
 * 6 4 
 * 3 6 
 * 1 5
 * 输出样例:
 * 0:4 1 
 * 1:2 0 
 * 2:5 3 1 
 * 3:5 4 2 
 * 4:0 5 3 
 * 5:2 3 4 
 ***********/

#include <iostream>
#include <vector>  // 包含vector
#include <algorithm>  // 包含reverse

using namespace std;

int main() {
    int n, m, s;  // 定义n、m、s
    cin >> n >> m >> s;  // 输入n、m、s
    vector<vector<int> > graph(n);  // 定义大小为n的vector graph
    for (int i = 0; i < m; i++) {  // 遍历i从0到m-1
        int a, b;  // 定义a、b
        cin >> a >> b;  // 输入a、b
        a--;  // a减1，因为编号从0开始
        b--;  // b减1，因为编号从0开始
        graph[a].push_back(b);  // a到b连边
        if (!s) {  // 如果是无向图
            graph[b].push_back(a);  // b到a连边
        }
    }
    for (int i = 0; i < n; i++) {  // 遍历i从0到n-1
        cout << i << ':';  // 输出i:
        vector<int> now = graph[i];  // 定义now为graph[i]
        reverse(now.begin(), now.end());  // 反转now，因为是表头插入法
        for (int j = 0; j < now.size(); j++) {  // 遍历j从0到now.size()-1
            cout << now[j] << ' ';  // 输出now[j]
        }
        cout << endl;  // 换行
    }
}