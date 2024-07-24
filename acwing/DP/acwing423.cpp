// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/425/)
 *    本题耗时：
 *    是否独立完成：是
 *    提交次数：1
 *    时间复杂度：O(T * M)
 *    空间复杂度：O(N)
 *    知识点：01背包
 *    解题思路：采草药的时间——代价，草药的价值——价值，限制的时间——背包的体积，每个草药只能被采一次——01背包
 *    技巧：01背包的代码中，每个物品的体积和价值只会在循环到该物品时被用到一次，因此我们可以边读入边处理
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
int f[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = T; j >= v; j--) f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[T];
    return 0;
}