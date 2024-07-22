// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1017/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(T * R * C)
 *    空间复杂度：O(N^2)
 *    知识点：线性DP，数字三角形模型
 *    解题思路：f[i][j]表示从(1, 1)走到(i, j)的所有路径的最大值，答案是f[r][c]，计算方法是每个方格要么从上边来，要么从左
 * 边来，所以有f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j]，边界是对于第一行和第一列的方格，只能从左/上来
 *    技巧：1. 通过初始化dp数组为最小值，就可以解决边界问题，因为从地图外走过来的值一定比从左边/上面走过来的值小
 *          2. 算法题中的网格图，不管它取的是点还是方格，最终总会落到二维数组中，从数组上考虑即可。
 *          3. 状态转移方程决定了必须以某种拓扑序计算状态。在线性DP中，一般只需要采用某种下标顺序即可。 
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：https://www.acwing.com/problem/content/1020/
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

const int N = 110;
int w[N][N];
int f[N][N];

void solve()
{
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> w[i][j];
        }
    }
    memset(f, 0, sizeof f);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
        }
    }
    cout << f[r][c] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}