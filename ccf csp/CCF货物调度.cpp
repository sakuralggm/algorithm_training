#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;
using pii = pair<int, int>;
const int N = 710, M = (N * 3 + 500 * 7 * 2) * 2 + 10, inf = 0x3f3f3f3f;

struct Edge
{
    int to, c, w, ne;
}edge[M];
int n, m, S, T;
int h[N], idx = 2;
int mf[N], d[N], pre[N];
bool vis[N];
int maxflow, mincost;

// 获取第a个点的第b天对应的节点编号
int get(int a, int b) 
{
    if (b == 8) b = 1; // 星期天的下一天是星期一
    return (a - 1) * 7 + b; // 城市1对应1~7，城市2对应8~14...，因此b是偏移量，城市1的从0开始偏移，城市2从7开始偏移,....
}

void add(int a, int b, int c, int w)
{
    edge[idx] = {b, c, w, h[a]}, h[a] = idx ++ ;
    edge[idx] = {a, 0, -w, h[b]}, h[b] = idx ++ ;
}

bool spfa()
{
    memset(d, 0x3f, sizeof d);
    memset(mf, 0, sizeof mf);
    queue<int> q;
    q.push(S), vis[S] = true, d[S] = 0, mf[S] = inf;
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        vis[t] = false;
        for (int i = h[t]; i; i = edge[i].ne)
        {
            auto e = edge[i];
            if (d[e.to] > d[t] + e.w && e.c)
            {
                d[e.to] = d[t] + e.w;
                mf[e.to] = min(mf[t], e.c);
                pre[e.to] = i;
                if (!vis[e.to]) q.push(e.to), vis[e.to] = true;
            }
        }
    }
    return mf[T] > 0;
}

void EK()
{
    while (spfa())
    {
        maxflow += mf[T];
        mincost += mf[T] * d[T];
        for (int i = T; i != S; i = edge[pre[i] ^ 1].to)
        {
            edge[pre[i]].c -= mf[T];
            edge[pre[i] ^ 1].c += mf[T];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    S = 0, T = n * 7 + 1; // 城市1对应1~7，城市2对应8~14...，所以选择0作为源点编号，n*7+1作为汇点编号
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= 7; j ++ ) // 由源点指向每个点的边
        {
            int a;
            cin >> a;
            add(S, get(i, j), a, 0);
        }
        for (int j = 1; j <= 7; j ++ ) // 由每个点指向汇点的边
        {
            int b;
            cin >> b;
            add(get(i, j), T, b, 0);
        }
        int v, w;
        cin >> v >> w;
        for (int j = 1; j <= 7; j ++ ) // 每个点指向下一天的点的边
            add(get(i, j), get(i, j + 1), v, w);
    }
    while (m -- )
    {
        int a, b, w;
        cin >> a >> b >> w;
        for (int i = 1; i <= 7; i ++ )
        {
            // 如果两座城市之间存在通路，建立由城市a的第i天的点指向城市b的第i天的点的边
            add(get(a, i), get(b, i), inf, w);
            add(get(b, i), get(a, i), inf, w);
        }
    }
    EK();
    cout << mincost;
    return 0;
}
