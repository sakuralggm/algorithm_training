/**
 *    题目链接：
 *    本题耗时：
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

queue<pii> q;
const int N = 1e5 + 10;
int cnt[N], ans;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    while (n -- ) {
        int t, k;
        cin >> t >> k;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            q.push({t, x});
            cnt[x]++;
            if (cnt[x] == 1) {
                ans++;
            }
        }
        while (q.size() && q.front().first <= t - 86400) {
            auto [x, y] = q.front();
            cnt[y]--;
            if (!cnt[y]) {
                ans--;
            }
            q.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}