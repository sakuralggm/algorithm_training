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

const int N = 1010;

struct Node
{
    int k1, k2; // 节点的k1，k2值
    int left, right; // 左右子树的编号
    int maxk1, mink2, mink1; // 以当前节点为根的子树的最大k1值，最小k1值，最小k2值
};
int n;
int in[N];
Node tr[N];


bool check(int u)
{
    // 获取当前节点的左右子树编号和k1, k2值
    int l = tr[u].left, r = tr[u].right, k1 = tr[u].k1, k2 = tr[u].k2;
    if (l == -1 && r == -1) // 如果当前节点是叶子节点
    {
        tr[u].maxk1 = tr[u].mink1 = k1; // 叶子节点的最大k1值和最小k1值都是自身的k1值
        tr[u].mink2 = k2; // 叶子节点的最小k2值是自身的k2值
        return true; // 返回true表示当前子树满足条件
    }
    bool lflag = true, rflag = true; // 初始化左右子树的检查标志为true
    if (l != -1) lflag = check(l); // 如果左子树存在，递归检查左子树
    if (r != -1) rflag = check(r); // 如果右子树存在，递归检查右子树
    if (lflag && rflag) // 如果左右子树都满足条件
    {
        if (l != -1) // 如果左子树存在
        {
            if (tr[l].maxk1 >= k1) return false; // 左子树的最大k1值不能大于等于当前节点的k1值
            if (tr[l].mink2 <= k2) return false; // 左子树的最小k2值不能小于等于当前节点的k2值
            tr[u].maxk1 = max(tr[l].maxk1, k1); // 更新当前节点的最大k1值
            tr[u].mink1 = min(tr[l].mink1, k1); // 更新当前节点的最小k1值
            tr[u].mink2 = min(tr[l].mink2, k2); // 更新当前节点的最小k2值
        }
        if (r != -1) // 如果右子树存在
        {
            if (tr[r].mink1 <= k1) return false; // 右子树的最小k1值不能小于等于当前节点的k1值
            if (tr[r].mink2 <= k2) return false; // 右子树的最小k2值不能小于等于当前节点的k2值
            tr[u].maxk1 = max(tr[r].maxk1, k1); // 更新当前节点的最大k1值
            tr[u].mink1 = min(tr[r].mink1, k1); // 更新当前节点的最小k1值
            tr[u].mink2 = min(tr[r].mink2, k2); // 更新当前节点的最小k2值
        }
        return true; // 返回true表示当前子树满足条件
    }
    else return false; // 如果左右子树有一个不满足条件，返回false
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tr[i].k1 >> tr[i].k2 >> tr[i].left >> tr[i].right;
        if (tr[i].left != -1) in[tr[i].left]++;
        if (tr[i].right != -1) in[tr[i].right]++;
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            root = i;
            break;
        }
    }
    if (check(root)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}