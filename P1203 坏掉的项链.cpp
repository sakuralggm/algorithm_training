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
const int N = 1010;
int lR[N], rR[N], lB[N], rB[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string a;
    int n;
    cin >> n >> a;
    a = ' '  + a + a + ' ';
    for (int i = 1; i <= 2 * n; i ++ )
    {
        if (a[i] == 'r') lR[i] = lR[i - 1] + 1;
        else if (a[i] == 'b') lB[i] = lB[i - 1] + 1;
        else if (a[i] == 'w') lR[i] = lR[i - 1] + 1, lB[i] = lB[i - 1] + 1;
    }
    for (int i = 2 * n; i >= 1; i -- )
    {
        if (a[i] == 'r') rR[i] = rR[i + 1] + 1;
        else if (a[i] == 'b') rB[i] = rB[i + 1] + 1;
        else if (a[i] == 'w') rR[i] = rR[i + 1] + 1, rB[i] = rB[i + 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n - 1; i ++ )
        ans = max(ans, min(n, max(lR[i], lB[i]) + max(rR[i + 1], rB[i + 1])));
    cout << ans;
    return 0;
}
