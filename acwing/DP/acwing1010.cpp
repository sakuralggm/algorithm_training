// clang-format off
/**
 *    题目链接：https://www.acwing.com/problem/content/1012/
 *    本题耗时：
 *    是否独立完成：否
 *    提交次数：1
 *    时间复杂度：O(n^2)
 *    空间复杂度：O(n)
 *    知识点：线性DP，最长上升子序列模型，贪心，Dilworth定理
 *    解题思路：第一问求的是最长不下降子序列。第二问，有两种做法：贪心和DP。
          1. 贪心：对于第i号导弹，要么选择末尾导弹高度最小的拦截系统，要么新创一个拦截系统，用一个数字即每套拦截系统此时所拦截的最后一个导弹高度，来表示该系统。这样就得到了一个数组，数组最终长度就是所需最少拦截系统数目。
          2. DP：可以转化为求最长上升子序列长度。证明：1)首先我们把这些导弹分为s组（s即为所求答案）可以看出每一组都是一个不升子序列；2) 划分完后我们在组1里取原序列中以组1的开头点为起点的连续的不升子串的最后一个元素，可以知道在组2中一定有一个大与它的点。因为如果组2中没有的话，那么组2中最高的导弹高度必然小于这个点，而其他的高度都小于这个高度而且是递减或相等的，那么没有必要再开一个组2了，矛盾，所以不存在找不到比它大的点的情况；3) 以此类推，对于每一个k组（1<=k<n）都可以找到这样的一些点。把这些点连起来，就是一条上升子序列。4) 设最长上升子序列长度为l，所求上升子序列为h，那么h<=l; 5) 因为最长上升子序列中任意两个点都不在一组内(如果在同一个组内，则每个组的数不成为一个不升子序列，矛盾）所以l==h。
 *    技巧：Dilworth定理（任何偏序集最小链划分的大小等于其最大反链的大小）。我们定义偏序关系为(i < j && a[i] >= a[j])，所以这个偏序集中的链就是不上升子序列，要求的就是最小链划分。但是，反链是定义在哈斯图上的，它与上升子序列没有必然的关系，但是我们可以构造出是上升子序列的任意长度反链（具体构造方法见解题思路中的证明），那么最长反链大小就是最长上升子序列的长度
 *    优化：
 *    错误：
 *    参考题解：
        1. 本题题解：https://www.acwing.com/solution/content/10173/ 
        2. Dilworth定理：http://chihaozhang.com/teaching/Comb2023/lec5/lec5.html
 *    同类题目：贪心的思想来源（区间分组模板题）：https://www.acwing.com/problem/content/908/
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

    int n = 0;
    int x;
    while (cin >> x)
    {
        a[++n] = x;
    }
    int noup = -2e9;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] >= a[i])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        noup = max(noup, f[i]);
    }
    cout << noup << "\n";
    int up = -2e9;
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
        up = max(up, f[i]);
    }
    cout << up << "\n";
    return 0;
}