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
double f[2][N];
double a[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    // f[0][i]：表示第i天结束时，手中为美元的最大利润；f[1][i]：表示第i天结束时，手中为马克的最大利润。
    // 要点：第i-1天的结束，就是第i天的开始
    f[0][0] = 100;
    for (int i = 1; i <= n; i ++ )
    {
        f[0][i] = max(f[0][i - 1], f[1][i - 1] * (100 / a[i]));
        f[1][i] = max(f[1][i - 1], f[0][i - 1] * (a[i] / 100));
    }
    cout << fixed << setprecision(2) << f[0][n];
    return 0;
}
