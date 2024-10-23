// clang-format off
/**
 *    [题目链接]()
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
// clang-format on
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

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    cin >> s;
    stack<char> stk;
    for (auto i : s)
    {
        if (stk.size() && i == ')' && stk.top() == '(') stk.pop();
        else stk.push(i);
    }
    int ln = 0, rn = 0;
    while (stk.size())
    {
        if (stk.top() == '(') ln++;
        else rn++;
        stk.pop();
    }
    cout << ceil(ln / 2.0) + ceil(rn / 2.0);
    return 0;
}