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

struct BiTree
{
    char data;
    BiTree *lchild, *rchild;
};

void build(BiTree **T)
{
    char ch;
    cin >> ch;
    if (ch == '#') *T = nullptr;
    else
    {
        *T = new BiTree;
        (*T)->data = ch;
        build(&((*T)->lchild));
        build(&((*T)->rchild));
    }
}

void inorder(BiTree **T)
{
    if (*T)
    {
        inorder(&((*T)->lchild));
        cout << (*T)->data;
        inorder(&((*T)->rchild));
    }
}

void exchange_child(BiTree **T)
{
    if (*T)
    {
        swap((*T)->lchild, (*T)->rchild);
        if (&((*T)->lchild)) exchange_child(&((*T)->lchild));
        if (&((*T)->rchild)) exchange_child(&((*T)->rchild));
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    BiTree *root = nullptr;
    build(&root);
    inorder(&root);
    exchange_child(&root);
    cout << "\n";
    inorder(&root);
    return 0;
}