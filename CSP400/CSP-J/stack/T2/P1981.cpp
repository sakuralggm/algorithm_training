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

const int mod = 10000;
stack<char> op;
stack<int> num;

void calc() {
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char opt = op.top();
    op.pop();
    if (opt == '*') {
        num.push(((ll)a * b) % mod);
    } else if (opt == '+') {
        num.push(((ll)a + b) % mod);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string formula;
    cin >> formula;
    for (int i = 0; i < formula.size(); i++) {
        if (isdigit(formula[i])) {
            int j = i, res = 0;
            while (j < formula.size() && isdigit(formula[j])) {
                res = res * 10 + formula[j] - '0';
                j++;
            }
            i = j - 1;
            num.push(res % mod);
        } else {
            if (formula[i] == '+') {
                while (op.size()) {
                    calc();
                }
            }
            op.push(formula[i]);
        }
    }
    while (num.size() > 1) {
        calc();
    }
    cout << num.top() % mod;
    return 0;
}