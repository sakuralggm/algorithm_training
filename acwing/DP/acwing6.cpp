// clang-format off
/**
 *    [题目链接](https://www.acwing.com/problem/content/description/6/)
 *    本题耗时：
 *    是否独立完成：否
 *    提交次数：3
 *    时间复杂度：O(m * n)
 *    空间复杂度：O(V)
 *    知识点：单调队列优化的多重背包
 *    解题思路：见基础算法模板——动态规划
 *    技巧：
 *    优化：
 *    错误：
 *    参考题解：https://www.bilibili.com/video/BV1354y1C7SF/
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

const int N = 2e4 + 10;
int f[N], g[N], q[N], hh, tt = -1;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int v, w, s;
    for (int i = 1; i <= n; i++)
    {
        memcpy(g, f, sizeof f); // g数组备份f上一轮的结果
        cin >> v >> w >> s; // 输入第i个物品的体积 价值 数量
        for (int j = 0; j < v; j++) // 按照法f[0]~f[m]按照下标模v的余数分成v个类
        {
            hh = 0, tt = -1; // 初始化单调队列
            for (int k = j; k <= m; k+=v) // 对每个类使用单调队列
            {
                // 窗口的宽度最大为s*v
                // 因为第i个物品最多能放入s个，这里参考朴素做法的第三次循环中的条件k<=s[i]
                // 如果q[hh]不在窗口[k - s*v, k - v]中，队头出队
                if (hh <= tt && q[hh] < k - s * v) hh++;
                // 使用队头最大值更新f
                if (hh <= tt) f[k] = max(g[k], g[q[hh]] + (k - q[hh]) / v * w);
                // 当前值比队尾值更有价值，队尾出队
                while (hh <= tt && g[k] >= g[q[tt]] + (k - q[tt]) / v * w) tt--;
                // 下标入队，而不是值入队，方便队头出队的判断
                q[++tt] = k;
            }
        }
    }
    cout << f[m];
    return 0;
}