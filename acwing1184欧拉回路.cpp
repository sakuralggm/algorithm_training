// #define LOCAL
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
const int N = 1e5 + 10, M = 4e5 + 10;
struct Edge
{
    int to, ne;
    bool used;
} e[M];
int h[N], idx = 2;
int in[N], out[N];
int stk[M], top;
int n, m, type;

void add(int a, int b)
{
    e[idx].to = b, e[idx].ne = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    while (h[u])
    {
        int t = h[u];
        if (e[t].used) // 删除头结点
        {
            h[u] = e[t].ne;
            continue;
        }
        e[t].used = true; // 不是直接在链表里删，而是先标记，等下次遇到时，该边就是链表的头结点，删除更方便
        if (type == 1) e[t ^ 1].used = true;
        dfs(e[t].to);
        // 把边的编号加入栈
        if (type == 1)
        {
            if (t & 1) stk[top ++ ] = -(t / 2);
            else stk[top ++ ] = t / 2;
        }
        else stk[top ++ ] = t - 1;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> type >> n >> m; // type=1无向图， type=2有向图
    int st = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        st = a;
        if (type == 1) add(a, b), add(b, a);
        else add(a, b);
        in[b] ++, out[a] ++ ;
    }
    // 度数条件
    bool flag = true;
    for (int i = 1; i <= n; i ++ )
    {
        if ((type == 1 && (in[i] + out[i]) & 1) || (type == 2 && (in[i] != out[i])))
        {
            flag = false;
            break;
        }
    }
    if (!flag) cout << "NO";
    else
    {
        dfs(st);
        if (top != m) flag = false;
        if (flag)
        {
            cout << "YES\n";
            for (int i = top - 1; i >= 0; i -- )
                cout << stk[i] << ' ';
        }
        else cout << "NO";
    }
    return 0;
}
