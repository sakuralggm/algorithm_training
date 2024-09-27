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

int N, M, K;

void solve()
{
    stack<int> stk;
    int x, cur = 1;
    vector<int> nums(N, 0);
    // 不能边读入边处理，因为如果提前返回，后面的输入不会被读到，会干扰下一次的处理。
    for (int i = 0; i < N; i++) cin >> nums[i]; 
    for (int i = 0; i < N; i++)
    {
        x = nums[i];
        if (x == cur)
        {
            cur++;
            while (stk.size() && stk.top() == cur) 
            {
                cur++;
                stk.pop();
            }
        }
        else
        {
            stk.push(x);
            if (stk.size() > M)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    if (stk.size()) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> M >> K;
    while (K -- )
    {
        solve();
    }
    return 0;
}