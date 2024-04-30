#define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int N = 1e4 + 10, M = 1e5 + 10;
multiset<int> g[N];
int n, m;
int d[N], stk[M], top;

void dfs(int u)
{
    while (g[u].size())
    {
        int t = *g[u].begin();
        g[u].erase(g[u].begin()); // 无向图要删两条边
        g[t].erase(g[t].find(u)); // 对于multiset,g[t].find(u)找到第一个u的iterator，把它指向的空间释放
        dfs(t);
    }
    stk[top ++ ] = u;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v), g[v].insert(u);
        d[u] ++ , d[v] ++ ;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (d[i] & 1) 
            cnt ++ ;
    }
    bool flag = true;
    if (!cnt) dfs(1);
    else if (cnt == 2 && (d[1] & 1)) dfs(1);
    else flag = false;
    if (top != m + 1) flag = false;
    if (flag)
    {
        for (int i = top - 1; i >= 0; i -- ) 
            cout << stk[i] << ' ';
    }
    else cout << -1;
    return 0;
}
