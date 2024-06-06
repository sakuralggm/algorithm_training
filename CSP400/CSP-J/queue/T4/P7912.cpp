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
// #define LOCAL
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

struct BLOCK {
    int st, ed, type;
};

queue<BLOCK> q;
const int N = 2e5 + 10;
int a[N];
bool used[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int pre = a[1], st = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != pre) {
            q.push({st, i - 1, a[i - 1]});
            st = i;
            pre = a[i];
        }
    }
    q.push({st, n, a[n]});
    queue<BLOCK> backup;
    while (q.size()) {
        backup = queue<BLOCK>();
        while (q.size()) {
            BLOCK t = q.front();
            q.pop();
            while (used[t.st] && t.st <= t.ed) {
                t.st++;
            }
            if (t.st <= t.ed) {
                cout << t.st << ' ';
                used[t.st] = true;
                t.st++;
            }
            if (t.st <= t.ed) {
                if (backup.size() && backup.back().type == t.type) {
                    backup.back().ed = t.ed;
                } else {
                    backup.push(t);
                }
            }
        }
        cout << "\n";
        q = backup;
    }
    return 0;
}