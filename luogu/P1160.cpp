/*
这个程序实现了一个双向链表的插入和删除操作。程序首先读取一个整数 n，表示要插入的节点数量。接着读取 n-1 对整数 k 和 p，表示在节点 k 的左边或右边插入新节点。然后读取一个整数 m，表示要删除的节点数量，并读取 m 个整数表示要删除的节点。最后输出链表中剩余的节点。

具体步骤如下：
1. 定义一个结构体 Node 表示链表节点，包含左右指针。
2. 定义一个数组 q 存储链表节点，数组 has_deleted 标记节点是否被删除。
3. 实现插入和删除操作的函数 insert 和 remove。
4. 在主函数中读取输入，执行插入和删除操作，最后输出链表中剩余的节点。
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

// 定义链表节点结构体
struct Node
{
    int l, r; // 左右指针
};
Node q[N]; // 存储链表节点的数组
bool has_deleted[N]; // 标记节点是否被删除

// 在节点 a 的右边插入节点 x
void insert(int a, int x)
{
    q[x].r = q[a].r; // x 的右指针指向 a 的右指针指向的节点
    q[x].l = a; // x 的左指针指向 a
    q[q[a].r].l = x; // a 的右指针指向的节点的左指针指向 x
    q[a].r = x; // a 的右指针指向 x
}

// 删除节点 x
void remove(int x)
{
    q[q[x].l].r = q[x].r; // x 的左指针指向的节点的右指针指向 x 的右指针指向的节点
    q[q[x].r].l = q[x].l; // x 的右指针指向的节点的左指针指向 x 的左指针指向的节点
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); // 关闭同步，加快读入输入的速度

    int n;
    cin >> n; // 读取节点数量

    // 将0作为链表的头节点（不存数据），数据从1开始。数组下标就是节点的编号
    q[0].r = 1; // 初始化链表头节点，0的右边是1
    q[1].l = 0, q[1].r = -1; // 初始化链表第一个节点，1·的左边是0，右边设为-1，表示链表结束。
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p; // 读取插入位置和方向
        if (p == 0) insert(q[k].l, i); // 在 k 的左边插入 i，在k的左边就是在k的左节点的右边插入i
        else insert(k, i); // 在 k 的右边插入 i
    }
    int m;
    cin >> m; // 读取要删除的节点数量
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x; // 读取要删除的节点
        if (has_deleted[x]) continue; // 如果节点已经被删除，跳过
        else
        {
            has_deleted[x] = true; // 标记节点已删除
            remove(x); // 删除节点
        }
    }
    for (int i = q[0].r; i != -1; i = q[i].r) // 输出链表中剩余的节点，前面说过，0是头节点，0的右边是第一个节点。之前把1号的节点的右节点设为-1，标志结束。那在插入的时候，尾结点左边插入的话，-1可以标志结束。在尾结点右边插入的话，新的尾结点的右节点还是-1，删除时同理。因此在我们的插入和删除操作中，一直维护了-1作为链表的结束标志这一个特性。
        cout << i << ' ';
    return 0;
}