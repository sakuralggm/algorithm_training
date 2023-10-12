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
int w[N];
int suffix[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    for (int i = n; i >= 1; i -- ) suffix[i] = max(suffix[i + 1], w[i]);
    int ans = 0;
    for (int i = 1; i < n; i ++ ) ans = max(ans, suffix[i + 1] - w[i]);
    cout << ans;
    return 0;
}
