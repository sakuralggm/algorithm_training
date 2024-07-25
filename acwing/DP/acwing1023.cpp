// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/1025/)
 *    本题耗时：3min
 *    是否独立完成：是
 *    提交次数：1
 *    时间复杂度：O(4 * M)
 *    空间复杂度：O(M)
 *    知识点：完全背包求装满背包容量的方案数
 *    解题思路：
            1. `f[i][j]`表示从前i本书中选，总体积恰好为j的方案的数量。
            2. 状态计算：`f[i][j] = f[i - 1][j] + f[i - 1][j - v[i]]`
            3. 边界：从前0本书中选，总价值为0的方案数是1，`f[0][0] = 1`。也可以说，从前i本书中选，总价值为0的方案数都是1（不选）, `f[i][0] = 1`。其他都初始化为0。
 *    技巧：
 *    优化：可以降为1维
 *    错误：如果只初始化了`f[0][0] = 1`，则体积必须从0开始循环，这样`f[i][0]`才能正确更新。
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

const int N = 1e3 + 10;
int f[N];
int v[] = {0, 10, 20, 50, 100};

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int m;
    cin >> m;
    f[0] = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[m];
    return 0;
}