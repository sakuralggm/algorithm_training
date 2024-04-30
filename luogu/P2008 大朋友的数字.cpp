// 做法1
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
const int N = 1e4 + 10;
int f[N], a[N], ind[N], sum[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1;
        for (int j = 1; j < i; j ++ )
            if (a[j] <= a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    for (int i = 1; i <= n; i ++ )
    {
        sum[i] = a[i];
        for (int j = 0; j < i; j ++ )
        {
            if (a[j] <= a[i] && f[j] + 1 == f[i])
            {
                sum[i] += sum[j];
                break; 
            }
        }
    }
    for (int i = 1; i <= n; i ++ ) cout << sum[i] << ' ';
    return 0;
}

// 做法2
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
const int N = 1e4 + 10;
int f[N], a[N], ind[N], sum[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1, sum[i] = a[i];
        for (int j = 1; j < i; j ++ )
        {
            if (a[j] <= a[i] && f[i] < f[j] + 1)
            {
                f[i] = f[j] + 1;
                sum[i] = sum[j] + a[i];
            }
        }
    }
    for (int i = 1; i <= n; i ++ ) cout << sum[i] << ' ';
    return 0;
}
