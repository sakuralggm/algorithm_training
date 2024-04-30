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
const int N = 110;
int tr[N][26], cnt[N], idx; // trie树
int ne[N]; // 回跳边
ll F[N][N], w[N][N]; // F是向量，w是转移矩阵，具体见题解
int n; // 模板串个数
ll m; // 主串长度

void insert(string s)
{
    int p = 0;
    for (int i = 0; s[i]; i ++ )
    {
        int u = s[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++ idx;
        p = tr[p][u];
    }
    cnt[p] ++ ;
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 26; i ++ )
    {
        if (tr[0][i]) 
            q.push(tr[0][i]);
    }
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 26; i ++ )
        {
            int k = tr[t][i];
            if (k) 
            {
                ne[k] = tr[ne[t]][i], q.push(k);
                cnt[k] += cnt[ne[k]];
            }
            else tr[t][i] = tr[ne[t]][i];
        }
    }
}

void mul(ll c[][N], ll a[][N], ll b[][N])
{
    static ll tmp[N][N];
    memset(tmp, -0x3f, sizeof tmp);
    for (int i = 0; i <= idx; i ++ )
        for (int j = 0; j <= idx; j ++ )
            for (int k = 0; k <= idx; k ++ )
                tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
    memcpy(c, tmp, sizeof tmp);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
    {
        string x;
        cin >> x;
        insert(x); // 构建trie树
    }
    build(); // 构建AC自动机
    // 计算转移矩阵
    memset(w, -0x3f, sizeof w);
    for (int i = 0; i <= idx; i ++ )
    {
        for (int j = 0; j < 26; j ++ )
        {
            int k = tr[i][j];
            w[i][k] = max(w[i][k], (ll)cnt[k]);
        }
    }
    for (int i = 1; i <= idx; i ++ ) F[0][i] = -0x3f3f3f3f; // DP初始化
    while (m) // 矩阵快速幂优化
    {
        if (m & 1) mul(F, F, w);
        mul(w, w, w);
        m >>= 1;
    }
    ll ans = 0;
    for (int i = 0; i <= idx; i ++ )
        ans = max(ans, F[0][i]); // F在计算时一直都在更新第0行
    cout << ans;
    return 0;
}
