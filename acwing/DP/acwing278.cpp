// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/280/)
 *    本题耗时：
 *    是否独立完成：模板题
 *    提交次数：1
 *    时间复杂度：O(N * M)
 *    空间复杂度：O(N * M)
 *    知识点：01背包，求装到指定容量的方案数
 *    解题思路：见常用代码模板——动态规划。简单来说就是将原来01背包中的状态属性max变为方案总和sum
 *    技巧：
 *    优化：可以优化为1维，空间复杂度O(M)
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
const int N = 110, M = 1e4 + 10;
int f[N][M], v[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] += f[i - 1][j - v[i]];
        }
    cout << f[n][m];
    return 0;
}