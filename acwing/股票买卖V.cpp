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
const int N = 1e5 + 10;
int w[N], f[N][2];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    f[1][1] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ )
    {
        f[i + 1][0] = max(f[i][0], f[i][1] + w[i]);
        f[i + 1][1] = max(f[i - 1][0] - w[i], f[i][1]);
    }
    cout << f[n + 1][0];
    return 0;
}
