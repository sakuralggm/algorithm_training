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

deque<int> q;
int cnt = 1;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    string ad, lr;
    int k;
    while (T -- ) {
        cin >> ad >> lr;
        if (ad == "D") {
            cin >> k;
        }
        if (ad == "A" && lr == "L") {
            q.push_front(cnt++);
        } else if (ad == "A" && lr == "R") {
            q.push_back(cnt++);
        } else if (ad == "D" && lr == "L") {
            while (k -- ) {
                q.pop_front();
            }
        } else if (ad == "D" && lr == "R") {
            while (k -- ) {
                q.pop_back();
            }
        }
    }
    for (auto i : q) {
        cout << i << "\n";
    }
    return 0;
}