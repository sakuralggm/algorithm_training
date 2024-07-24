// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/description/274/)
 *    本题耗时：
 *    是否独立完成：否
 *    提交次数：2
 *    时间复杂度：O(n^2)
 *    空间复杂度：O(n^2)
 *    知识点：线性DP，最长上升子序列模型，最长公共子序列模型
 *    解题思路：具体见DP分析图。有状态表示可知，结果要给所有以b[i](1<=i<=n)的公共上升子序列的最大值取一个max。所有包含a[i]的公共上升子序列的划分方式是倒数第二个字符是空、b[1]、b[2]、...、b[j - 1]。
 *    技巧：画出dp数组的二维表，更容易找到优化的方法。
 *    优化：按照DP分析图写的做法是O(n^3)的，可以通过代码的等价变形优化为O(n^2)。首先搞清楚，f[i][j]由谁更新。一个是f[i-1][j]，这个不需要优化。需要优化的是f[i-1][k](k<j且b[k]<b[j])。只有当a[i]==b[j]时，才会计算第二种情况，所以可以等价为f[i-1][k](k<j且b[k]<a[i])。我们的下标顺序中是先固定i,然后递增j，因此在算f[i][k](1<=k<=n)时，a[i]是固定的。再分析，f[i][k1]需要max{f[i-1][k]}, k<k1&&b[k]<a[i], 而f[i][k1+1]需要max{f[i-1][k']}, k'<k1+1&&b[k]<a[i], 后者只需要前者与f[i-1][k1]去一次max即可得到。因此，我们可以定义一个变量val来存储f[i-1][k], k<j&&b[k]<a[i], 这个变量会在j递增时不断更新, 即可满足状态转移方程的需求。
 *    错误：
 *    参考题解：
 *    同类题目：https://www.luogu.com.cn/problem/CF10D
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
const int N = 3e3 + 10;
int a[N], b[N], f[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        int val = 0;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(val + 1, f[i][j]);
            if (b[j] < a[i]) val = max(val, f[i - 1][j]);
        }
    }
    int ans = -2e9;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}