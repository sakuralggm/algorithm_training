// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1014/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(n^2)
 *    空间复杂度：O(n)
 *    知识点：线性DP，最长上升子序列模型
 *    解题思路：这道题难点在于转换。一个合法的航线方案要满足：对于航线i和j，如果i在j之前，则i的北岸和南岸的点的坐标都要小于j的，这样才能不交叉。于是我们可以先将所有点对按照北岸坐标从小到大排序，那么合法的航线方案就与南岸坐标的上升子序列一一对应。转换为求排序后的南岸坐标序列的最长上升子序列。
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

const int N = 5010;
pii a[N];
int f[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j].second < a[i].second)
            {
                f[i] = max(f[i], f[j] + 1);
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