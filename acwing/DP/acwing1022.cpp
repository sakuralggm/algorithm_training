// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/1024/)
 *    本题耗时：
 *    是否独立完成：例题
 *    提交次数：1
 *    时间复杂度：O(N * M * K)
 *    空间复杂度：O(N * M)
 *    知识点：二维费用的背包问题
 *    解题思路：将收服需要的精灵球数量和造成的伤害作为费用，精灵的数量作为价值，每个精灵有收服和收服两个选项，因此这是一个二维费用的背包问题。
 *    技巧：
 *    优化：观察到精灵数量很少，可以将收服的精灵数量和耗费的体力作为代价，精灵球数量作为价值，复杂度为O(K^2 * M)
            1. 状态表示：`f[i][j][k]`表示从前i个小精灵中选，耗费体力不超过j, 收服小精灵数量为k的选择方案的精灵球数量最小值
            2. 状态计算：
                * `f[i][j][k]` = `f[i - 1][j][k]`;
                * 当j >= 收服第i个小精灵耗费的体力值时, `f[i][j][k]` = `min(f[i][j][k], f[i - 1][j - d][k - 1]) + c` (d为收服该小精灵的体力值, c为收服该小精灵的精灵球数量)
            3. 目标：`f[K][M - 1][ans]`, 其中ans从K递减到1, 只要`f[K][M - 1][ans] <= N`(精灵球总数)即合法，第一个满足的为最多收服的精灵数量。
            4. 边界：`f[i][j][0] = 0`, 即收服0个精灵不需要精灵球。
            5. 最小体力：对于满足`f[K][M - 1][i] <= N`的最大i, 对`f[K][j][i]`循环j，表示从前K个物品中选, 耗费体力不超过j, 收服i个精灵的最少精灵球数量，只要它满足所需精灵球数量小于等于N即合法，找到最小的体力j。
 *    错误：
        1. 初始化边界错误，一开始将f[0][i][j]都置为0，发现没有用，关键还是在收服精灵数为0时不耗费精灵球上。
        2. 寻找最小体力方法错误，循环了f[K][j][i] == f[K][M - 1][i], 没有认识到f[K][j][i]就是收服了i个精灵的状态，搞混了价值和费用。
 *    参考题解：https://www.acwing.com/solution/content/4640/
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
const int N = 1010, M = 510;
int f[N][M];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, cnt; // 精灵球数量、初始体力值、小精灵数量
    cin >> n >> m >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int num, injure;
        cin >> num >> injure; // 收服需要的精灵球数量和造成的伤害
        for (int j = n; j >= num; j--)
        {
            for (int k = m; k >= injure; k--)
            {
                f[j][k] = max(f[j][k], f[j - num][k - injure] + 1);
            }
        }
    }
    int res = m - 1; // 不能消耗完体力，所以取m-1
    for (int i = 0; i <= m - 1; i++)
    {
        if (f[n][i] == f[n][m - 1])
        {
            res = min(res, i);
        }
    }
    cout << f[n][m - 1] << ' ' << m - res << "\n"; 
    return 0;
}