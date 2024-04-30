#include <bits/stdc++.h>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
using ll = long long;
using pii = pair<int, int>;
const int N = 510;
int g[N][N];
int n;

pii now = {1, 1};

void move1(int u)
{
    if (u == 0) now.y += 1;
    else now.x += 1;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> g[i][j];
    pii ed = {n, n};
    int move_flag = 0, move1_flag = 0, move2_flag = 0;
    while (1)
    {
        if (now == ed) 
        {
            cout << g[now.x][now.y] << ' ';
            break;   
        }
        
        if (!move_flag)
        {
            cout << g[now.x][now.y] << ' ';
            move1(move1_flag);
            if (now == pii(n, 1) || now == pii(1, n)) move1_flag ^= 1;
            move1_flag ^= 1;
        }
        else
        {
            if (!move2_flag)
            {
                while (now.x != n && now.y != 1)
                {
                    cout << g[now.x][now.y] << ' ';
                    now.x += 1, now.y -= 1;
                }
            }
            else 
            {
                while (now.x != 1 && now.y != n)
                {
                    cout << g[now.x][now.y] << ' ';
                    now.x -= 1, now.y += 1;
                }
            }
            move2_flag ^= 1;
        }
        move_flag ^= 1;
    }
    return 0;
}
