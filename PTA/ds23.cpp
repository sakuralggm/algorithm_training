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

const int N = 15;

int maze[N][N];
pii pre[N][N];
int n;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void dfs(int x, int y)
{
    maze[x][y] = 1;
    if (x == n - 2 && y == n - 2)
    {
        stack<pii> ans;
        ans.push({n - 2, n - 2});
        int a = pre[n - 2][n - 2].first, b = pre[n - 2][n - 2].second;
        while (a != 1 || b != 1)
        {
            ans.push({a, b});
            int ta = a, tb = b;
            a = pre[ta][tb].first, b = pre[ta][tb].second;
        }
        ans.push({1, 1});
        while (ans.size())
        {
            auto t = ans.top();
            ans.pop();
            cout << '(' << t.first << ',' << t.second << ')';
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (maze[xx][yy] != 1)
        {
            pre[xx][yy] = {x, y};
            dfs(xx, yy);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    dfs(1, 1);
    if (maze[n - 2][n - 2] != 1) cout << "NO";
    return 0;
}