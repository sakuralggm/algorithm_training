// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/8/)
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(N * V * M)
 *    空间复杂度：O(N * V * M)
 *    知识点：动态规划，二维费用背包的01背包
 *    解题思路：见分析图
 *    技巧：
 *    优化：可以用滚动数组优化掉第一维（枚举物品），将空间复杂度降为O(V * M)
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
const int N1 = 1e3 + 10, N2 = 110;
int f[N1][N2][N2], v[N1], m[N1], w[N1];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N, V, M;
    cin >> N >> V >> M;
    for (int i = 1; i <= N; i++) cin >> v[i] >> m[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= V; j++)
            for (int k = 0; k <= M; k++)
            {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= v[i] && k >= m[i])
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - v[i]][k - m[i]] + w[i]);
            }
    cout << f[N][V][M];
    return 0;
}