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
bool isfirst = true;

void print(queue<int> & stk)
{
    if (isfirst) 
    {
        cout << stk.front();
        isfirst = false;
    }
    else cout << ' ' << stk.front();
    stk.pop();
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    queue<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0) b.push(x);
        else a.push(x);
    }
    while (a.size() || b.size())
    {
        if (a.size() >= 2)
        {
            print(a);
            print(a);
        }
        else if (a.size() == 1) print(a);
        
        if (b.size()) print(b);
    }
    return 0;
}