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
int ls[N], rs[N];
vector<int> lvl[N];
int maxlvl;

void dfs(int u, int l)
{
    maxlvl = max(maxlvl, l);
    lvl[l].push_back(u);
    if (ls[u]) dfs(ls[u], l + 1);
    if (rs[u]) dfs(rs[u], l + 1);
}

void insert(int u, int x)
{
    if (x > u)
    {
        if (ls[u] == 0) ls[u] = x;
        else insert(ls[u], x);
    }
    else 
    {
        if (rs[u] == 0) rs[u] = x;
        else insert(rs[u], x);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int root = 0;
    cin >> root;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }
    dfs(root, 1);
    for (int i = 1; i <= maxlvl; i++)
    {
        for (auto j : lvl[i])
        {
            if (i > 1) cout << ' ';
            cout << j;
        }
    }
    cout << "\n";
    int mx = floor(log2(n + 1) - 1);
    if (lvl[maxlvl - 1].size() == pow(2, mx)) cout << "YES";
    else cout << "NO";
    return 0;
}