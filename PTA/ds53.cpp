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

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> lvl[N];
int maxlvl = 0;

void dfs(int u, int l)
{
    lvl[l].push_back(u);
    maxlvl = max(maxlvl, l);
    for (auto v : g[u]) dfs(v, l + 1);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != -1) g[x].push_back(i);
        else root = i;
    }
    dfs(root, 1);
    sort(lvl[maxlvl].begin(), lvl[maxlvl].end());
    cout << maxlvl << endl;
    for (int i = 0; i < lvl[maxlvl].size(); i++)
    {
        if (!i) cout << lvl[maxlvl][i];
        else cout << ' ' << lvl[maxlvl][i];
    }
    return 0;
}