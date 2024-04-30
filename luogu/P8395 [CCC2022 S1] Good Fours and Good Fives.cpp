// 解法1 参数整数划分问题https://www.acwing.com/problem/content/902/
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
const int N = 1e6 + 10;
int f[3][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i <= n; i ++ ) 
    {
        if (i % 4 == 0)
            f[1][i] = 1; // 从前1个数（4）当中选，和为i的方案数
    }
    for (int i = 0; i <= n; i ++ )
    {
        f[2][i] = f[1][i];
        if (i >= 5) f[2][i] += f[2][i - 5]; // 从前2个数当中选，和为i的方案数（完全背包）
    }
    cout << f[2][n];
    return 0;
}

// 解法2 f[i] = f[i - n1] + f[i - n2]
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
const int N = 1e6 + 10;
int f[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    // 避免重复，先加4，再加5。
    // 比如f[i - 4]的方案是5,5,4,那从它转移过来就是5,5,4,4。
    // f[i - 5]的方案是5,4,4，那从它转移过来就是5,4,4,5。
    // 这两种方案是一个方案，但是如果直接f[i] = f[i - 4] + f[i - 5]会记成2次
    f[4] = 1;
    for (int i = 1; i <= n; i ++ )
        if (i - 4 > 0) 
            f[i] = f[i - 4];
    f[5] = 1;
    for (int i = 1; i <= n; i ++ ) 
        if (i - 5 > 0)
            f[i] += f[i - 5];
    cout << f[n];
    return 0;
}
