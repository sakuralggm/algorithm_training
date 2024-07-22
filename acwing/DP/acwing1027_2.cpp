// clang-format off
/**
 *    题目链接：
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
#define debug(x) cerr << #x << ' ' << '=' << ' ' << x << endl
#else
#define dbg(...)
#define debug(x)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int N = 15;
int w[N][N];
int f[N * 2][N][N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int r, c, v;
    while (cin >> r >> c >> v, r || c || v)
    {
        w[r][c] = v;
    }
    for (int k = 2; k <= n + n; k++)
    {
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) // 坐标要合法
                {
                    int t = w[i1][j1];
                    if (i1 != i2)
                    {
                        t += w[i2][j2];
                    }
                    f[k][i1][i2] = max({ f[k - 1][i1][i2], f[k - 1][i1][i2 - 1], f[k - 1][i1 - 1][i2],
                                         f[k - 1][i1 - 1][i2 - 1] }) +
                                   t;
                }
            }
        }
    }
    cout << f[n + n][n][n];
    return 0;
}