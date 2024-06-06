/**
 *    题目链接：https://www.luogu.com.cn/problem/P1540
 *    本题耗时：10min
 *    提交次数：1
 *    时间复杂度：
 *    空间复杂度：
 *    知识点：
 *    解题思路：
 *    技巧：
 *    优化：每次不需要遍历队列查找，可以使用计数数组，因为输入的整数小于等于1000
 *    错误：
 *    参考题解：
 *    同类题目：
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

const int N = 1e3 + 10;
int q[N], hh, tt;
int n, m;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> m >> n;
    int ans = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bool flag = true;
        for (int j = hh; j < tt; j++) {
            if (q[j] == x) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
            if (tt - hh <= m - 1) {
                q[tt++] = x;
            } else {
                hh++, q[tt++] = x;
            }
        }
    }    
    cout << ans;
    return 0;
}