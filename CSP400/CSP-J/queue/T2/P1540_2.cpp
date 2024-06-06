/**
 *    题目链接：https://www.luogu.com.cn/problem/P1540
 *    本题耗时：10min
 *    提交次数：1
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
int cnt[N];
int n, m;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> m >> n;
    int ans = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (cnt[x] == 0) {
            ans++;
            if (tt - hh <= m - 1) {
                q[tt++] = x;
                cnt[x]++;
            } else {
                cnt[q[hh]]--, hh++, q[tt++] = x, cnt[x]++;
            }
        }
    }    
    cout << ans;
    return 0;
}