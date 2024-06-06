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

const int N = 1e6 + 10;
int a[N];
int q[N], hh, tt;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        while (hh < tt && i - q[hh] >= k) {
            hh++;
        }
        while (hh < tt && a[q[tt - 1]] > a[i]) {
            tt--;
        }
        q[tt++] = i;
        if (i >= k - 1) {
            cout << a[q[hh]] << ' ';
        }
        for (int i = hh; i < tt; i++) {
            dbg("%d ", q[i]);
        }
        dbg("\n");
    }
    cout << "\n";
    hh = tt = 0;
    for (int i = 0; i < n; i++) {
        while (hh < tt && i - q[hh] >= k) {
            hh++;
        }
        while (hh < tt && a[q[tt - 1]] < a[i]) {
            tt--;
        }
        q[tt++] = i;
        if (i >= k - 1) {
            cout << a[q[hh]] << ' ';
        }
    }
    return 0;
}