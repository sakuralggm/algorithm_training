#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 100010, M = N * 2, INF = 0x3f3f3f3f;

int n, m;
int pr[N]; // 每个城市的价格
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
struct Query
{
    int a, b; // 起点是a，终点是b，最小花费是c
    LL c;
}query[N]; // 存储所有询问
vector<int> Q[N]; // Q[i]为编号为i的整棵树的询问
int bel[N]; // 子树的编号
int fp[N][17], fu[N][17], dist[N], cm[N]; // fp是祖先，fu是st表，存区间最小值点， cm是起点到根路径上的最小价格，dist是点到根节点的距离
LL cs[N]; // 从起点到根节点的花费
vector<PII> qt[N]; // qt[b]存储路径起点在另一棵子树，路径终点是b的所有询问，存了起点的编号和询问在query数组的下标，用于求出结果后赋值给query[k].c
LL cs2[N]; // 存的是从根节点到该点的最小花费
int minp[N], minu[N], top; // 存的是从根节点到当前点的最小价格和取到最小价格的点， top是计数器，表示这两个数组的大小

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int get_size(int u, int fa)  // 求子树大小
{
    if (st[u]) return 0;
    int res = 1;
    for (int i = h[u]; ~i; i = ne[i])
        if (e[i] != fa)
            res += get_size(e[i], u);
    return res;
}

int get_wc(int u, int fa, int tot, int& wc)  // 求重心
{
    if (st[u]) return 0;
    int sum = 1, ms = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        int t = get_wc(j, u, tot, wc);
        ms = max(ms, t);
        sum += t;
    }
    ms = max(ms, tot - sum);
    if (ms <= tot / 2) wc = u; // 这里不是真的要求出重心，而是只要子树节点数最大值<=n/2就认为这个点是重心，不影响时间复杂度
    return sum;
}

void dfs1(int u, int fa, int id) // 求起点到根节点的花费
{
    if (st[u]) return;
    bel[u] = id, qt[u].clear();
    fp[u][0] = fa, fu[u][0] = u; // 以u为左端点，区间长度为1的最小值点是u自己
    for (int i = 1; i < 17; i ++ ) // 预处理倍增数组
    {
        int p = fp[u][i - 1];
        fp[u][i] = fp[p][i - 1];
        if (pr[fu[u][i - 1]] <= pr[fu[p][i - 1]]) fu[u][i] = fu[u][i - 1];
        else fu[u][i] = fu[p][i - 1];
    }
    if (pr[fu[u][16]] == pr[u])  // 特判特殊情况，最小的是自己，不需要二分
    {
        cs[u] = (LL)dist[u] * pr[u];
        cm[u] = pr[u];
    } 
    else // 否则拼凑出从起点到根节点路径上第一个比起点小的点
    {
        int x = u;
        for (int i = 16; i; i -- )
            if (pr[fu[x][i - 1]] >= pr[u]) // 假设两者的深度差为y，在跳和不跳的组合下，y会被2的整数次幂拼凑，最后到达那个点（LCA）
                x = fp[x][i - 1];

        cs[u] = (LL)(dist[u] - dist[x]) * pr[u] + cs[x]; // 分成两段求，递推，x在路径上，因此cs[x]已经求过
        cm[u] = cm[x]; // x是路径上第一个比u小的，则u到根节点路径上的最小价格由cm[x]递推
    }

    for (int i = h[u]; ~i; i = ne[i]) // 递归所有子节点的cs和cm
    {
        int j = e[i];
        if (j != fa && !st[j])
        {
            dist[j] = dist[u] + w[i];
            dfs1(j, u, id); // 继承子树编号
        }
    }
}

void dfs2(int u, int fa)
{
    if (st[u]) return;
    if (minp[top - 1] < pr[u]) minp[top] = minp[top - 1], minu[top] = minu[top - 1]; // 存前缀的最小值
    else minp[top] = pr[u], minu[top] = u;
    top ++ ;

    for (int i = 0; i < qt[u].size(); i ++ ) // 求以u点为终点的所有询问
    {
        int a = qt[u][i].x, k = qt[u][i].y; // 询问的起点和下标
        if (cm[a] <= minp[top - 1]) query[k].c = cs[a] + (LL)dist[u] * cm[a]; // 从起点到根节点的最小价格比从根节点到当前的最小价格小
        else // 对于每个询问，二分出从根节点到u的路径上第一个比cm[]小的点
        {
            int l = 0, r = top - 1;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (minp[mid] < cm[a]) r = mid;
                else l = mid + 1;
            }
            int ver = minu[r]; // 第一个小于cm[a]的点的编号，minu存的是从根节点到当前点的前缀最小点的编号
            query[k].c = cs[a] + cs2[u] - cs2[ver] + (LL)dist[ver] * cm[a]; // 二分之后分成两段来算 cs[a]从起点到根，
            // cs2[u] - cs2[ver]从二分出的点到终点
            // (LL)dist[ver] * cm[a]是从根到终点路径的前半段
        }
    }

    for (int i = h[u]; ~i; i = ne[i]) // 搜索子节点，递归
    {
        int j = e[i];
        if (j != fa && !st[j])
        {
            cs2[j] = cs2[u] + (LL)minp[top - 1] * w[i];
            dfs2(j, u);
        }
    }
    top -- ; // minp,minu每次只存从根节点到u的路径上的信息，u的询问解决后，退回去，直到最后退掉出了根节点外的所有点，在记录另一条路径
}

void calc(int u)
{
    if (st[u]) return; // 如果该点已被处理，直接return 
    vector<int> q; // 先将整棵树的询问存下来（备份），因为后面某个点的询问会变
    q.swap(Q[u]);
    get_wc(u, -1, get_size(u, -1), u); // get_wc找重心， get_size求以某个点为根的子树大小，这里的最后一个参数是引用，会把u变成重心
    st[u] = true;  // 删除重心

    for (int i = 0; i < 17; i ++ ) fp[u][i] = 0, fu[u][i] = u; // 初始化倍增数组，根节点的祖先是0，ST表中的最小值点是自己
    dist[u] = cs[u] = 0, cm[u] = pr[u], bel[u] = 0, qt[u].clear(); // 初始化求前半段需要用到的变量
    for (int i = h[u]; ~i; i = ne[i]) // 第一种遍历，遍历从s到根的所有权值
    {
        int j = e[i];
        dist[j] = dist[u] + w[i]; // 算点到根节点的距离
        dfs1(j, u, j); // 第三个参数是子树的编号，即该子树的所有点的都属于该子树
    }

    for (int i = 0; i < q.size(); i ++ ) // 遍历以u为根的树的所有询问，将所有的询问分类
    {
        int k = q[i]; // q存的是这棵树所有询问的下标，k是这棵树的第i个询问在query数组中的下标，用来查到询问的具体内容
        int a = query[k].a, b = query[k].b; // a，b为询问的起点和终点
        if (b == u) query[k].c = cs[a]; // 如果路径的端点是根节点，直接处理
        else if (bel[a] == bel[b]) Q[bel[a]].push_back(k); // 起点和终点编号相同，代表它们是在子树中的路径，不穿过根节点。如果询问未穿过根节点，把询问放在子树里
        else qt[b].push_back({a, k}); // 否则该询问的两个端点在不同子树内，将询问插入到路径终点是b的vector中，表示所有以这个点为终点的询问的起点有哪些
    }

    cs2[u] = 0, minp[0] = pr[u], minu[0] = u, top = 1; // top - 1是当前路径的最后一个点
    for (int i = h[u]; ~i; i = ne[i]) // 第二种遍历，求从根到终点的花费，对于每个花费都要枚举所有起点，每个起点都要二分一下，分段求价值
    {
        int j = e[i];
        cs2[j] = cs2[u] + (LL)minp[top - 1] * w[i]; // 从根节点到终点路径上的第一个点的花费？
        dfs2(j, u);
    }

    for (int i = h[u]; ~i; i = ne[i]) // 点分治，递归求解
    {
        int j = e[i];
        if (Q[j].size()) calc(j);
    }
}

int main()
{
    scanf("%d%d", &n, &m); // 读入点数和询问的数量
    pr[0] = INF; // 边界，0号点设为正无穷，处理倍增的边界问题
    for (int i = 1; i <= n; i ++ ) scanf("%d", &pr[i]); // 读入每个点的价格
    memset(h, -1, sizeof h); // 初始化邻接表
    for (int i = 0; i < n - 1; i ++ ) // 读入边
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    // 将所有的询问先存到一个点里，在分治时，先将所有穿过根节点的询问得出答案，其他询问放在对应的子树里，放的方式是复制
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        query[i] = {a, b}; // 存下第i个询问
        if (a != b) Q[1].push_back(i);
    }
    // 点分治
    calc(1);

    for (int i = 0; i < m; i ++ ) // 打印第i个询问的结果
        printf("%lld\n", query[i].c);

    return 0;
}
