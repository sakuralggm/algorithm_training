// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1016/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(n^2)
 *    空间复杂度：O(n)
 *    知识点：线性DP，最长上升子序列模型
 *    解题思路：根据题目分析，游览路线一定是先上升后下降的，目标是求最长的这样形状的路线。从峰点分析，左边是以从左往右看以峰点为结尾的最长上升子序列，右边是从右往左看以峰点为结尾的最长上升子序列，且左右两边是相互独立的。所以只需要分别从左往右和从右往左求一次最长上升子序列，然后看哪个点的左右两边的和加起来最大即可。
 *    技巧：
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：https://www.acwing.com/problem/content/484/
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

const int N = 1e3 + 10;
int a[N], f[N], g[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j]) 
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        g[i] = 1;
        for (int j = n; j > i; j--)
        {
            if (a[i] > a[j])
            {
                g[i] = max(g[i], g[j] + 1);
            }           
        }
    }
    int res = -2e9;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, f[i] + g[i] - 1);
    }
    cout << res << "\n";
    return 0;
}