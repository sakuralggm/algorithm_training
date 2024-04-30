#define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cerr << #x << ' ' <<  '=' << ' ' << x << endl
#else
#define dbg(...)
#define debug(x)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vv = vector<vector<ll>>;
const int N = 1e4 + 10, M = 30;
int n, d;

vv read(int r, int c)
{
    vv res;
    for (int i = 0; i < r; i ++ )
    {
        vector<ll> a(c, 0);
        for (int j = 0; j < c; j ++ ) cin >> a[j];
        res.push_back(a);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> d;
    vv q = read(n, d);
    vv k = read(n, d);
    vv v = read(n, d);
    vv w = read(1, n);

    vv kv;
    for (int i = 0; i < d; i ++ )
    {
        vector<ll> t(d, 0);
        for (int j = 0; j < d; j ++ )
        {
            for (int u = 0; u < n; u ++ )
            {
                t[j] += k[u][i] * v[u][j];
            }
        }
        kv.push_back(t);
    }
    vv qkv;
    for (int i = 0; i < n; i ++ )
    {
        vector<ll> t(d, 0);
        for (int j = 0; j < d; j ++ )
        {
            for (int u = 0; u < d; u ++ )
            {
                t[j] += q[i][u] * kv[u][j];
            }
        }
        qkv.push_back(t);
    }
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < d; j ++ )
            qkv[i][j] *= w[0][i];
    }
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < d; j ++ )
            cout << qkv[i][j] << ' ';
        cout << "\n";
    }
    return 0;
}
