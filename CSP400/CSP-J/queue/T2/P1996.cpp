/**
 *    题目链接：
 *    本题耗时：
 *    提交次数：
 *    时间复杂度：O(n*m) cnt从0到m又到0，一共n次
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int cnt = 0;
    while (q.size()) {
        cnt++;
        if (cnt == m) {
            auto t = q.front();
            cout << t << ' ';
            q.pop();
            cnt = 0;
        } else {
            auto t = q.front();
            q.pop();
            q.push(t);
        }
    }
    return 0;
}