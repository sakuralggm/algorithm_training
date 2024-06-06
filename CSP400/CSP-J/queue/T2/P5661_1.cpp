/**
 * 题目链接：https://www.luogu.com.cn/problem/P5661
 * 本题耗时：1h
 * 提交次数：
 * 是否独立完成：是
 * 时间复杂度：
 * 空间复杂度：
 * 知识点：
 * 解题思路：
 * 技巧：
 * 优化：
 * 错误：
 * 参考题解：
 * 同类题目：
 * 初始写法：
 * 优化写法：
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
int head = -1, tail = -1, e[N], ne[N], idx, ti[N];

void pop_head() {
    head = ne[head];
}
void push(int x, int t) {
    if (head == -1) {
        e[idx] = x, ti[idx] = t, ne[idx] = head, head = idx, tail = idx++;
    } else {
        e[idx] = x, ti[idx] = t, ne[idx] = ne[tail], ne[tail]=idx, tail = idx++;
    }
}
bool pop(int x) {
    int pre = head;
    for (int i = head; i != -1; i = ne[i]) {
        int j = e[i];
        if (j >= x) {
            if (i == head) {
                pop_head();
            } else {
                ne[pre] = ne[i];
                if (i == tail) {
                    tail = pre;
                }
            }
            return true;
        }
        pre = i;
    }
    return false;
}
void clean(int t) {
    while (head != -1 && t - ti[head] > 45) {
        pop_head();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    int type, money, clock;
    for (int i = 0; i < n; i++) {
        cin >> type >> money >> clock;
        clean(clock);
        if (type == 0) {
            ans += money;
            push(money, clock);
        } else {
            if (!pop(money)) {
                ans += money;
            }
        }
    }
    cout << ans;
    return 0;
}