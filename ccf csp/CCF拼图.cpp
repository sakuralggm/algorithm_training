#include <bits/stdc++.h>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
using ll = long long;
using pii = pair<int, int>;
const int N = 130, mod = 1e9 + 7;

int w[N][N];
int F[N][N]; // 注意虽然F[][]矩阵真正有用的的只有第一行，但是函数不仅要处理f*w, 还要处理w*w，因此要保证f和w是同形的，都是N*N
ll n, m;

void dfs(int now, int next, int index)
{
    if (index == m)
    {
        w[now][next] += 1;
        return;
    }
    else if ((now >> index) & 1) dfs(now, next, index + 1);
    else
    {
        if (index > 0 && !((next >> index) & 1) && !((next >> (index - 1) & 1))) // case1
            dfs(now, next + (1 << index) + (1 << (index - 1)), index + 1);
        if (index < m - 1 && !((next >> index) & 1) && !((next >> (index + 1)) & 1)) // case 2
            dfs(now, next + (1 << index) + (1 << (index + 1)), index + 1);
        if (index < m - 1 && !((now >> (index + 1)) & 1))
        {
            if (!((next >> index) & 1)) // case3
                dfs(now, next + (1 << index), index + 2);
            if (!((next >> (index + 1)) & 1)) // case4
                dfs(now, next + (1 << (index + 1)), index + 2);
        }
    }
}

// 矩阵乘法，注意虽然F[][]矩阵真正用到的只有第一行，但是这个函数不仅要处理f*w, 还要处理w*w，因此要保证f和w是同形的，都是N*N
void mul(int c[][N], int a[][N], int b[][N])
{
    static int tmp[N][N]; // 防止每次都开一个新的
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < (1 << m); i ++ )
        for (int j = 0; j < (1 << m); j ++ )
            for (int k = 0; k < (1 << m); k ++ )
                tmp[i][j] = (tmp[i][j] + (ll)a[i][k] * b[k][j]) % mod;
    memcpy(c, tmp, sizeof tmp);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    // 求转移矩阵
    for (int i = 0; i < (1 << m); i ++ )
        dfs(i, 0, 0);
    F[0][(1 << m) - 1] = 1; // 初始化边界
    while (n) // 矩阵快速幂求F[0]*w^n，即F[0] * w^n = F[0] * w^(2^i) * w^(2^j) * ...
    {
        if (n & 1) mul(F, F, w);
        mul(w, w, w);
        n >>= 1;
    }
    cout << F[0][(1 << m) - 1]; // 此时的F[0][2^m-1]就是f[n][2^m-1]
    return 0;
}
