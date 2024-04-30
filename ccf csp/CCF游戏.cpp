// #define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int N = 110, M = 310; // M取310的原因，题目给出一个障碍存在的最晚时刻是100，从101时刻出发，最多走200多步到终点，所以取310
int n, m, t;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
struct Triple
{
    int x, y, t;
};
bool g[N][N][M];
bool st[N][N][M];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m >> t;
    for (int i = 0; i < t; i ++ )
    {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        for (int j = a; j <= b; j ++ ) g[r][c][j] = true;
    }
    queue<Triple> q;
    q.push({1, 1, 0});
    
    while (q.size())
    {
        auto h = q.front();
        q.pop();
        int x = h.x, y = h.y, t = h.t; 
        for (int i = 0; i < 4; i ++ )
        {
            int xx = x + dx[i], yy = y + dy[i], tt = t + 1;
            if (xx == n && yy == m)
            {
                cout << t + 1;
                return 0;
            }
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !g[xx][yy][tt] && !st[xx][yy][tt]) 
            {
                q.push({xx, yy, tt});
                st[xx][yy][tt] = true;
            }
        }
    }
    return 0;
}
