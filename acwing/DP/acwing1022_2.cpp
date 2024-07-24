// clang-format off
/**
 *    [题目链接]()
 *    本题耗时：
 *    是否独立完成：
 *    提交次数：
 *    时间复杂度：
 *    空间复杂度：
 *    知识点：
 *    解题思路：
 *    技巧：
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：
 *    初始写法：
 *    优化写法：
**/
// clang-format on
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

const int N1 = 510, N2 = 110; // 体力最大为N1，精灵数量最大为N2
int f[N2][N1][N2];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N, M, K; // 精灵球数量，初始体力值，小精灵数量
    cin >> N >> M >> K;
    memset(f, 0x3f, sizeof f); // 求最小值，初始化为最大

    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            f[i][j][0] = 0;
        }
    }
    for (int i = 1; i <= K; i++) // 从前i个小精灵中选
    {
        int c, d;
        cin >> c >> d; 
        for (int j = 0; j <= M; j++)
        {
            for (int k = 1; k <= K; k++)
            {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= d && k >= 1)
                {
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j - d][k - 1] + c);
                }
            }
        }
    }
    int n = -1, m = 2e9;
    for (int i = K; i >= 0; i--)
    {
        if (f[K][M - 1][i] <= N)
        {
            n = i;
            for (int j = 0; j < M; j++)
            {
                if (f[K][j][i] <= N) // 从前K个物品中选, 耗费体力不超过j, 收服k个精灵的最少精灵球数量
                {
                    m = j;
                    break;
                }
            }
            break;
        }
    }
    cout << n << ' ' << M - m;
    return 0;
}