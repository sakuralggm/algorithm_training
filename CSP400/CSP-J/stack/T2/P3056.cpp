/**
 *    题目链接：
 *    本题耗时：
 *    是否独立完成：
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 0; i < n; i++) {
        cout << f[i] << ' ';
        dbg("a[%d] = %d\n",i ,f[i]);
    }
    return 0;
}