// clang-format off
/**
 *    [题目链接]()
 *    本题耗时：
 *    是否独立完成：
 *    提交次数：
 *    时间复杂度：
 *    空间复杂度：
 *    知识点：
 *    解题思路：
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
const int N1 = 110, N2 = 1010;
int f[N1][N1], w[N2], v[N2], m[N2];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N, M, V;
    cin >> N >> V >> M;
    for (int i = 1; i <= N; i++) cin >> v[i] >> m[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            for (int k = M; k >= m[i]; k--)
                f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
    cout << f[V][M];
    return 0;
}