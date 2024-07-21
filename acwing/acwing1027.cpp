// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1029/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(n^4)
 *    空间复杂度：O(n^4)
 *    知识点：线性DP，数字三角形模型
 *    解题思路：
 *      1. 走两次可以看成两个人一起走
        2. 那么就可以用f[i][j][k][l]表示第一个人从（1,1）走到(i, j),第二个人从(1, 1)走到(k, l)的最大值
        3. 如果一个点被取了两次，即i == k && j == l, 就少加一个w[i][j]，表示少取一次
        4. 状态转移方程是第一个人从左/上来，第二个人从左/上来，2*2一共4种情况
 *    技巧：这道题的最大特点是一个方格中的数只能被取1次，对于一个状态f[i1][j1][i2][j2]，我们假设前面的路径重合情况都已经处理好了，就看现在这个时刻，如果此时这两条路径重合，我们就少加1个w[i1][j1]，表示只取一次，每次重合都这样处理，那只取一次的限制就被满足了。
 *    优化：目前我们是两个人各走各的，即这两个人的步数可以不一样。我们可以令两个人同时走，即两个人的步数总是相同的，这样我们就可以用一个k来表示他们的步数，(i1,j1)和(i2,j2)就可以写成(i1,k-i1),(i2,k-i2)。对于一个方格只能取一次的限制，只需看i1是否等于i2即可。从这个问题来看，先后走和同时走的结果是相同的，因为我们只关注路径是否是从(1,1)到(n,n)，走的顺序在满足限制的条件下是无关的。
 *    错误：
 *    参考题解：
 *    同类题目：https://www.acwing.com/problem/content/277/
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
int f[N][N][N][N];

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
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                for (int j2 = 1; j2 <= n; j2++)
                {
                    int t = w[i1][j1];
                    if (i1 != i2 && j1 != j2)
                    {
                        t += w[i2][j2];
                    }
                    f[i1][j1][i2][j2] = max({ f[i1][j1 - 1][i2][j2 - 1], f[i1][j1 - 1][i2 - 1][j2],
                                              f[i1 - 1][j1][i2][j2 - 1], f[i1 - 1][j1][i2 - 1][j2] }) +
                                        t;
                }
            }
        }
    }
    cout << f[n][n][n][n];
    return 0;
}