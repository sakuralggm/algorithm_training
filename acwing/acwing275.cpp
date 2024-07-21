// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/277/
 *    本题耗时：
 *    是否独立完成：是
 *    提交次数：2
 *    时间复杂度：O((m+n) * m * m)
 *    空间复杂度：O((m+n) * m * m)
 *    知识点：线性DP，数字三角形模型
 *    解题思路：一来一回地走，可以看成(1,1)走到(m,n)两次，思路和acwing1027方格取数相同。
 *    技巧：
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：https://www.acwing.com/problem/content/1029/
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

const int N = 60;
int w[N][N], f[N * 2][N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    for (int k = 2; k <= m + n; k++)
    {
        for (int i1 = 1; i1 <= m; i1++)
        {
            for (int i2 = 1; i2 <= m; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
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

    cout << f[m + n][m][m];
    return 0;
}