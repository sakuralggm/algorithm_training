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

const int N = 100;
vector<int> g[N];
pii tree[N];
bool visited[N];

void DFSTree(int u)
{
    visited[u] = true;
    int q = -1;

    bool first = true;
    for (int v : g[u])
    {
        if (!visited[v])
        {
            if (first)
            {
                tree[u].first = v;
                first = false;
            }
            else
            {
                tree[q].second = v;
            }
            q = v;
            DFSTree(q);
        }
    }
}

void DFSForest()
{
    int root = -1;
    int q = -1;

    for (int i = 0; i < 13; i++) tree[i] = {-1, -1};
    for (int i = 0; i < 13; i++)
    {
        if (!visited[i])
        {
            if (root == -1) root = i;
            else tree[q].second = i;
            q = i;
            DFSTree(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    g[0].push_back(1);
    g[0].push_back(4);
    g[0].push_back(5);
    g[0].push_back(6);
    g[1].push_back(2);
    g[1].push_back(3);
    g[2].push_back(3);
    g[2].push_back(6);
    g[7].push_back(8);
    g[9].push_back(10);
    g[9].push_back(11);
    g[9].push_back(12);
    g[10].push_back(11);
    g[1].push_back(0);
    g[4].push_back(0);
    g[5].push_back(0);
    g[6].push_back(0);
    g[2].push_back(1);
    g[3].push_back(1);
    g[3].push_back(2);
    g[6].push_back(2);
    g[8].push_back(7);
    g[10].push_back(9);
    g[11].push_back(9);
    g[12].push_back(9);
    g[11].push_back(10);

    DFSForest();
    for (int i = 0; i < 13; i++)
    {
        cout << i << " " << tree[i].first << " " << tree[i].second << endl;
    }
    return 0;
}