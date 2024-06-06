/**
 *    题目链接：
 *    本题耗时：
 *    提交次数：
 *    时间复杂度：
 *    空间复杂度：
 *    知识点：
 *    解题思路：
 *    技巧：
 *    错误：
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
struct Node {
    int money, time;
    bool used;
};
Node q[N];
int head, tail;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    int money, type, clock;
    for (int i = 0; i < n; i++) {
        cin >> type >> money >> clock;
        while (head < tail && clock - q[head].time > 45) {
            head++;
        }
        if (type == 0) {
            ans += money;
            q[tail] = {money, clock, false};
            ++tail;
        } else {
            bool flag = true;
            for (int i = head; i <= tail; i++) {
                if (q[i].money >= money && q[i].used == false) {
                    q[i].used = true;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans += money;
            }
        }
    }
    cout << ans;
    return 0;
}