// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1018/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(n^2)
 *    空间复杂度：O(n)
 *    知识点：线性DP，最长上升子序列模型
 *    解题思路：将最长上升子序列中的长度换成和即可。
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

const int N = 1e3 + 10;
int a[N], f[N];

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
        f[i] = a[i];
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
    }
    int res = -2e9;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, f[i]);
    }
    cout << res;
    return 0;
}