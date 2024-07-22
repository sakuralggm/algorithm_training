// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1019/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(K * N^2)
 *    空间复杂度：O(N)
 *    知识点：线性DP, 最长上升子序列模型
 *    解题思路：对于一个起点和一个方向，实际上问的就是从这个点往这个方向最多有多少个下降的点，可以看成反过来以这个点为结尾的最长上升子序列的长度。有两个方向，这两个方向是相互独立的，就是分别求这两个方向的最长上升子序列长度，取一个max。最终的答案就是每一个点的最长长度中再取一个最大值
 *    技巧：不需要先求每个点的最长长度，然后再取最大值，这种做法是O(n^3)的。在最长上升子序列的模板中，以每一点结尾的最长上升子序列长度是一个一个求出来的，后面的点的长度对前面的点没有影响，所以我们可以在DP过程中取max即可。这样时间复杂度就是O(n^2)的。
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

const int N = 110;
int h[N],f[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    int res = -2e9;
    // 从左到右求最长上升子序列
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }
    // 从右到左求最长上升子序列
    for (int i = n; i >= 1; i--)
    {
        f[i] = 1;
        for (int j = n; j > i; j--)
        {
            if (a[j] < a[i])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while (T -- )
    {
        solve();
    }
    return 0;
}