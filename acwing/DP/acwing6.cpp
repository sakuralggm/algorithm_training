// clang-format off
/**
 *    [题目链接]()
 *    本题耗时：
 *    是否独立完成：
 *    提交次数：
 *    时间复杂度：
 *    空间复杂度：
 *    知识点：
 *    解题思路：
 *    技巧：
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：
 *    初始写法：
 *    优化写法：
**/
// clang-format on
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
const int N = 1e3 + 10, V = 2e4 + 10;
int f[N][V], w[N], v[N], s[N];
int g[N][V];
int q[V], hh, tt = -1;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++)
    {
        hh = 0, tt = -1;
        for (int j = 0; j <= m; j++)
        {
            int maxs = min(j / v[i], s[i]), curw = f[i - 1][j];
            int minv = j - maxs * v[i];
            dbg("\n%d %d\n", i, j);
            for (int i = hh; i <= tt; i++) 
            {
                dbg("%d ", q[i]);
            }
            dbg("\n");
            debug(maxs);
            debug(curw);
            debug(minv);
            debug(tt);
            while (hh <= tt && q[hh] < minv) hh++;
            while (hh > 0 && q[hh] > minv) hh--;
            for (int i = hh; i <= tt; i++) 
            {
                dbg("%d ", q[i]);
            }
            dbg("\n");
            while (hh <= tt && f[i - 1][q[tt]] + min((j - q[tt]) / v[i], s[i]) * w[i] < curw) tt--;
            for (int i = hh; i <= tt; i++) 
            {
                dbg("%d ", q[i]);
            }
            dbg("\n");
            q[++tt] = j;
            f[i][j] = f[i - 1][q[hh]] + min((j - q[hh]) / v[i], s[i]) * w[i];
            for (int i = hh; i <= tt; i++) 
            {
                dbg("%d ", q[i]);
            }
            dbg("\n");
            dbg("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
            {
                g[i][j] = max(g[i][j], g[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dbg("%d ", g[i][j]);
        }
        dbg("\n");
    }
    dbg("\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dbg("%d ", f[i][j]);
        }
        dbg("\n");
    }
    cout << f[n][m];
    return 0;
}