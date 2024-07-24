// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/description/189/)
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：
 *    空间复杂度：
 *    知识点：线性DP，最长上升子序列模型，搜索。贪心
 *    解题思路：每个点可能属于上升序列或者下降序列，用暴搜枚举即可。在枚举它属于哪种序列后，要用贪心的方式将其加入（先看看能不能加到现有的序列中，不行再自己开一个新的序列），保证最少。
 *    技巧：用DFS暴搜时，维护当前最优解，当答案大于最优解时剪枝
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：这道题是[拦截导弹问题](https://www.acwing.com/problem/content/1012/)再套上一层暴搜
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
int ans;
int up[N], down[N], a[N];
int n;

void dfs(int u, int cntup, int cntdown)
{
    if (cntup + cntdown >= ans) return;
    if (u == n)
    {
        ans = cntup + cntdown;
        return;
    }

    // 将a[u]放入上升子序列
    int indup = 0;
    while (indup < cntup && up[indup] >= a[u]) indup++;
    int t = up[indup]; // 需要恢复现场
    up[indup] = a[u]; 
    if (indup == cntup) dfs(u + 1, cntup + 1, cntdown);
    else dfs(u + 1, cntup, cntdown);
    up[indup] = t; 

    // 将a[u]放入下降子序列
    int inddown = 0;
    while (inddown < cntdown && down[inddown] <= a[u]) inddown++;
    t = down[inddown]; // 需要恢复现场
    down[inddown] = a[u];
    if (inddown == cntdown) dfs(u + 1, cntup, cntdown + 1);
    else dfs(u + 1, cntup, cntdown);
    down[inddown] = t;
}

void solve()
{
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = n;
    dfs(0, 0, 0);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    while (cin >> n, n) 
    {
        solve();
    }
    return 0;
}