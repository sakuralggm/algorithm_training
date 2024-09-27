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

    int n, m;
    cin >> n >> m;
    while (n -- )
    {
        stack<char> stk;
        string s;
        bool flag = true;
        cin >> s;
        for (auto i : s)
        {
            if (i == 'S')
            {
                if (stk.size() == m) 
                {
                    cout << "NO\n";
                    flag = false;
                    break;
                }
                else stk.push(i);
            }
            else if (i == 'X')
            {
                if (stk.empty())
                {
                    cout << "NO\n";
                    flag = false;
                    break;
                }
                else stk.pop();
            }
        }
        if (flag)
        {
            if (stk.empty()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}