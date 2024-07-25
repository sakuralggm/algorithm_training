// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/description/1021/)
 *    本题耗时：5min
 *    是否独立完成：是
 *    提交次数：1
 *    时间复杂度：O(N * M)
 *    空间复杂度：O(M)
 *    知识点：多重背包
 *    解题思路：这是一道多重背包的裸题，我用单调队列优化的写法来做
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
const int M = 6010;
int f[M], g[M], q[M], hh, tt = -1;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int v, w, s;
    for (int i = 1; i <= n; i++)
    {
        memcpy(g, f, sizeof f);
        cin >> v >> w >> s;
        for (int j = 0; j < v; j++)
        {
            hh = 0, tt = -1;
            for (int k = j; k <= m; k+=v)
            {
                if (hh <= tt && q[hh] < k - s * v) hh++;
                if (hh <= tt) f[k] = max(g[k], g[q[hh]] + (k - q[hh]) / v * w);
                while (hh <= tt && g[k] >= g[q[tt]] + (k - q[tt]) / v * w) tt--;
                q[++tt] = k; 
            }
        }
    }
    cout << f[m];
    return 0;
}