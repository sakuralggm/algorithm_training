/*
1. 满二叉树: 一个二叉树，如果每一个层的结点数都达到最大值，则这个二叉树就是满二叉树。也就是说，如果一个二叉树的层数为K，且结点总数是2^k - 1，则它就是满二叉树。

2. 完全二叉树: 完全二叉树是效率很高的数据结构，完全二叉树是由满二叉树而引出来的。对于深度为K的，有n个结点的二叉树，当且仅当其每一个结点都与深度为K的满二叉树中编号从1至n的结点一一对应时称之为完全二叉树。 要注意的是满二叉树是一种特殊的完全二叉树。

3. 判断完全二叉树: 从根节点开始层序遍历，如果遇到一个结点，其左孩子为空，右孩子不为空，则不是完全二叉树；如果遇到一个结点，其左孩子不为空，右孩子为空或者左右孩子都为空，则之后的结点都必须是叶子结点（没有左右孩子），否则不是完全二叉树。
实现方法：bfs，还可以顺便得到层序遍历序列。
*/
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
int ls[N], rs[N];
vector<int> lvl[N];
int maxlvl;

void insert(int u, int x)
{
    if (x > u)
    {
        if (ls[u] == 0) ls[u] = x;
        else insert(ls[u], x);
    }
    else 
    {
        if (rs[u] == 0) rs[u] = x;
        else insert(rs[u], x);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int root = 0;
    cin >> root;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }
    vector<int> ans;
    bool iscomplete = true;
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        ans.push_back(t);
        if (ls[t] && rs[t]) q.push(ls[t]), q.push(rs[t]);
        else if (!ls[t] && rs[t]) 
        {
            iscomplete = false;
            q.push(rs[t]);
        }
        else
        {
            if (ls[t]) q.push(ls[t]);
            while (q.size())
            {
                auto t = q.front();
                q.pop();
                ans.push_back(t);
                if (ls[t])
                {
                    iscomplete = false;
                    q.push(ls[t]);
                }
                if (rs[t])
                {
                    iscomplete = false;
                    q.push(rs[t]);
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << "\n";
    cout << (iscomplete ? "YES" : "NO") << '\n';
    return 0;
}