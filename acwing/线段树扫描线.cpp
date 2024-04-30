#include <bits/stdc++.h>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
using ll = long long;
using pii = pair<int, int>;

// 宏定义线段树的左右儿子，注意使用宏定义时父节点的变量名是u
#define ls (u << 1)
#define rs (u << 1 | 1)
const int N = 2e5 + 10; // 1e5个矩形，2e5个x，2e5个y
struct Line 
{
    int x1, x2, y; // 扫描线就是矩形的上边和下边，记录该扫描线两个端点的x值，用于求覆盖范围
    int tag; // 上边还是下边，上边为1，下边为-1
    bool operator < (Line &t)  // 从下往上扫描，按高度排序
    {
        return y < t.y;
    }
}lines[N];
struct Tree 
{
    int l, r; // 线段树的区间，l,r是区间的左右端点
    int cnt, len; // 区间被完全覆盖的次数和区间对当前扫描线贡献的区间长度
}tree[N * 8]; // 代码中会访问最后一层节点的左右儿子，开八倍，如果不需要访问最后一层的左右儿子，开四倍
int xs[N];

// 建立以u为根节点，区间范围是[l,r]的线段树
void build(int u, int l, int r)
{
    tree[u] = {l, r, 0, 0};
    if (l == r) return; // 如果是叶子结点，返回
    else // 否则递归建树
    {
        int mid = l + r >> 1;
        build(ls, l, mid), build(rs, mid + 1, r);
    }
}

void pushup(int u) // 更新区间对当前扫描线的长度
{
    int l = tree[u].l, r = tree[u].r; // 区间的左右端点
    if (tree[u].cnt) tree[u].len = xs[r + 1] - xs[l]; // 如果cnt>0，说明该区间被扫描线完全覆盖，贡献全部长度
    else tree[u].len = tree[ls].len + tree[rs].len; // 否则该区间贡献的长度是左右儿子的贡献之和
}

// 区间修改
void modify(int u, int l, int r, int tag)
{
    if (l > tree[u].r || r < tree[u].l) return; // 区间和扫描线覆盖的范围没有交集，越界返回
    if (l <= tree[u].l && tree[u].r <= r)  // 区间被扫描线完全覆盖
    {
        tree[u].cnt += tag; // 用tag修改cnt，-1说明离开了覆盖该区间的一个矩形，1说明进入了覆盖该区间的一个矩形
        pushup(u); // 更新该区间的贡献长度，如果cnt=0，则len被修改为0，否则len=区间长度
        return;
    }
    else // 区间未被扫描线完全覆盖
    {
        modify(ls, l, r, tag); // 先算出左右儿子的长度贡献
        modify(rs, l, r, tag);
        pushup(u); // 用左右儿子的贡献来修改它的len
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i ++ ) // 要离散化，从1开始存
    {
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {x1, x2, y1, 1}; // 技巧，要同时存入上边和下边，分别存在i和n+i就不会和其他的扫描线发生下标冲突
        lines[n + i] = {x1, x2, y2, -1};
        xs[i] = x1, xs[n + i] = x2; // 保存所有x，用线段树维护
    }

    n *= 2; // 乘2方便操作
    sort(lines + 1, lines + n + 1); // 按高度排序，用于从下往上扫描
    sort(xs + 1, xs + n + 1); // 对所有的x做离散化 三部曲1. 排序 2. 去重 3. 二分寻址
    // 区间都是用离散化后xs的下标表示
    // 要取出真实的x坐标时，就索引xs数组
    // 计算时r+1，传参时r-1
    int ed = unique(xs + 1, xs + n + 1) - xs - 1;
    build(1, 1, ed - 1); // 注意，这里用了右端点偏移映射，区间下标为[l,r]，对应的x范围是[xs[l], xs[r+1]]，这里的l,r是xs数组的下标，就用它来表示区间的左右端点
                        // 比如区间的x范围是[10, 40]，xs:10, 20, 30, 40，下标:1,2,3,4，则线段树中，区间[10, 40]的节点的l,r是1,3

    ll ans = 0; // 1e9，可能爆int
    for (int i = 1; i < n; i ++ )
    {
        int l = lower_bound(xs + 1, xs + ed + 1, lines[i].x1) - xs; // 二分查找离散化后扫描线的左右端点对应的下标
        int r = lower_bound(xs + 1, xs + ed + 1, lines[i].x2) - xs;
        modify(1, l, r - 1, lines[i].tag); // 区间修改
        ans += (ll)tree[1].len * (lines[i + 1].y - lines[i].y);
    }
    cout << ans;
    return 0;
}
