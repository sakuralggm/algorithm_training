// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/1026/)
 *    本题耗时：
 *    是否独立完成：是
 *    提交次数：1
 *    时间复杂度：O(n * V)
 *    空间复杂度：O(V)
 *    知识点：01背包
 *    解题思路：题目问使箱子的剩余空间为最小的选法，则所选物品的总体积要最大，因此我们可以把物品的体积作为价值，同时每个物品只能选一次，是01背包问题。
 *    技巧：可以边读入边处理。
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
const int N = 2e4 + 10;
int f[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int V;
    cin >> V;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v; 
        cin >> v;
        for (int j = V; j >= v; j--) f[j] = max(f[j], f[j - v] + v);
    }
    cout << V - f[V] << "\n";
    return 0;
}