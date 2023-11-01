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
const int N = 510, M = 1010;
#define ls (u << 1)
#define rs (u << 1 | 1)
struct User
{
    int id;
    unordered_map<int, int> right;
    User(): id(), right{} {}
    bool operator < (const User &w) const
    {
        return id < w.id;
    }
};
struct Expr
{
    int attr, val;
    bool type;
    bool isatom;
    Expr(): attr(), val(), type(), isatom() {}
}exprs[M];

bool judge_atom(User &usr, Expr &e) // 叶子节点的判断
{
    if (e.type && usr.right.count(e.attr) && usr.right[e.attr] == e.val) return true;
    else if (!e.type && usr.right.count(e.attr) && usr.right[e.attr] != e.val) return true;
    else return false;
}

void move(string &op, int &idx) // 把下标增加到到不是括号的字符上
{
    while (idx < op.size() && (op[idx] == '(' || op[idx] == ')')) 
        idx ++ ;
}

void build(int u, string &op, int &idx) // 建立表达式树
{
    move(op, idx);
    if (idx >= op.size()) return;
    if (op[idx] == '&' || op[idx] == '|')  // 有逻辑符号，就不是叶子结点了
    {
        exprs[u].type = op[idx] == '|' ? 1 : 0; // 或是1，与是0
        exprs[u].isatom = false;
        idx ++ ;
        build(ls, op, idx);
        idx ++ ;
        build(rs, op, idx);
    }
    else  // 不是逻辑符号，也不是括号，那就是数字，是叶子结点
    {
        exprs[u].isatom = true;
        int ind = idx;
        while (ind < op.size() && op[ind] != '~' && op[ind] != ':') ind ++ ;
        exprs[u].attr = stoi(op.substr(idx, ind - idx));
        if (op[ind] == ':') exprs[u].type = 1; // :是1，~是0
        else exprs[u].type = 0;
        int end = ind;
        while (end < op.size() && op[end] != ')') end ++ ;
        exprs[u].val = stoi(op.substr(ind + 1, end - ind - 1));
        idx = end;
    }
}

bool judge(User &usr, int u) // 递归判定用户是否满足表达式
{
    auto &e = exprs[u];
    if (e.isatom) return judge_atom(usr, e); // 叶子节点直接判定
    else // 否则返回左右子树的结果的运算
    {
        if (e.type) return judge(usr, ls) | judge(usr, rs); // 或
        else return judge(usr, ls) & judge(usr, rs); // 且
    }
}

vector<User> users; // 存所有用户的信息
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;  
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        User a;
        int cnt;
        cin >> a.id >> cnt;
        for (int j = 0; j < cnt; j ++ )
        {
            int k, v;
            cin >> k >> v;
            a.right[k] = v;
        }
        users.push_back(a);
    }
    sort(users.begin(), users.end()); // 按照dn从小到大排序，后面遍历完可以直接输出结果了
    int m;
    cin >> m;
    string op;
    for (int i = 0; i < m; i ++ )
    {
        cin >> op;
        memset(exprs, 0, sizeof exprs); // 每次都要清空树，再重新建树
        int idx = 0;
        build(1, op, idx);
        vector<int> res;
        for (auto &usr : users) // 遍历所有用户判定
        {
            if (judge(usr, 1)) 
                res.push_back(usr.id);
        }
        for (auto &x : res) cout << x << ' '; // 输出结果
        cout << "\n";
    }
    return 0;
}
