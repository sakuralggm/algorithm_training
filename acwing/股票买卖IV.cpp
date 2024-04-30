#define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 10, inf = 0x3f3f3f3f, M = 110;
int w[N];
int f[N][M][2];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    
    // 第0天结束，第1天开始时，交易次数只能是0，大于0的不合法
    // 第0天结束，第1天开始时，不能持有股票。
    for (int j = 0; j <= k+1; j ++ ) f[0][j][0] = -inf, f[0][j][1] = -inf; 
    // 第1天开始时，交易0次，不持有股票是合法的，利润为0
    f[0][1][0] = 0;
    // 任何一天的交易次数都不能是负数, j->j+1， 因此j=0是就是负数
    for (int i = 0; i <= n; i ++ ) f[i][0][0] = -inf, f[i][0][1] = -inf;
    // 简单写法 memset(f, -0x3f, sizeof f); f[0][1][0] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j <= k; j ++ )
        {
            f[i][j + 1][0] = max(f[i - 1][j + 1][0], f[i - 1][j + 1][1] + w[i]);
            f[i][j + 1][1] = max(f[i - 1][j + 1][1], f[i - 1][j][0] - w[i]);
        }
    }
    int res = 0;
    for (int j = 0; j <= k; j ++ ) res = max(res, f[n][j + 1][0]);
    cout << res;
    return 0;
}
