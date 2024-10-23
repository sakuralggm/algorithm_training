#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector<int> tr[N];

void dfs(int u, int fa)
{
    printf("入%d\n",u);
    for (auto v : tr[u])
    {
        if (v == fa)
            continue;
        printf("下%d\n",u);
        dfs(v, u);
        printf("回%d\n",u);
    }
    printf("离%d\n",u);
}

int main()
{
    tr[1].push_back(5);
    tr[1].push_back(4);
    tr[2].push_back(5);
    tr[3].push_back(6);
    tr[4].push_back(1);
    tr[5].push_back(1);
    tr[5].push_back(2);
    tr[5].push_back(6);
    tr[5].push_back(7);
    tr[6].push_back(3);
    tr[6].push_back(5);
    tr[6].push_back(8);
    tr[7].push_back(5);
    dfs(1, 0);
    return 0;
}