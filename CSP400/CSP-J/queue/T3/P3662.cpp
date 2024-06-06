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

const int N = 1e5 + 10;
bool st[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }
    int ans = 2e9, cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        while (i - q.front() + 1 > k) {
            if (st[q.front()]) {
                cnt--;
            }
            q.pop();
        }
        q.push(i);
        if (st[i]) {
            cnt++;
        }
        if (i >= k) {
            ans = min(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}