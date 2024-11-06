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


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    // 可以建模成哈夫曼树
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1) 
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans << endl;
    return 0;
}