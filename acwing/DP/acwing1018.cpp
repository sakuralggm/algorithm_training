/**
 *    题目链接：https://www.acwing.com/problem/content/1020/
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(n^2)
 *    空间复杂度：O(n^2)
 *    知识点：线性DP，数字三角形模型
 *    解题思路：题目中最多不超过2n-1的时间，从(1,1)到(n,n)，需要横走n步(穿过第1,2,3,...,n个格子)，再竖走n-1步(从1到2,2到3,...,n-1到n)，总共2n-1步，说明只能向右或向下走
 *    技巧：是求最小值，对于边界情况（第1行和第1列），我们可以初始化dp数组为最大值，这样从地图外走的代价一定更大，同时特殊处理第一个点f[1][1] = w[1][1].
 *    优化：
 *    错误：
 *    参考题解：
 *    同类题目：https://www.acwing.com/problem/content/1017/
 *    初始写法：
 *    优化写法：
**/
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
int w[N][N];
int f[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1) 
            {
                f[i][j] = w[i][j];
            }
            else
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + w[i][j];
            }
        }
    }
    cout << f[n][n];
    return 0;
}