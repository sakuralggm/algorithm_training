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

#define x first
#define y second
#define ls (u << 1)
#define rs (u << 1 | 1)

using ll = long long;
using pii = pair<int, int>;
const int N = 3e5 + 10;
struct Node
{
    int l, r;
    int v, c;
}tr[N * 4];
pii p[N];
vector<int> xs;
int up[N], down[N];
int best;

// 用左右儿子的v和c来更新当前点的v和c
void pushup(int u)
{
    tr[u].v = max(tr[ls].v, tr[rs].v);
    tr[u].c = tr[ls].c + tr[rs].c;
}
// 单点修改
void update(int u, int x)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].v = min(up[x], down[x]);
        tr[u].c = tr[u].v >= best;
    }
    else 
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) update(ls, x);
        else update(rs, x);
        pushup(u);
    }
}
// 区间查询，返回一个pair，first存区间的最大值，second存区间和
pii query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r) return {tr[u].v, tr[u].c};
    else
    {
        pii res(-1, 0);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) 
        {
            auto t = query(ls, l, r); // bug1 r <- mid
            res.x = max(res.x, t.x);
            res.y += t.y;
        }
        if (r > mid)
        {
            auto t = query(rs, l, r); // bug2 l <- mid + 1
            res.x = max(res.x, t.x);
            res.y += t.y;
        }
        return res;
    }
}
// 初始化线段树
void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, 0};
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(ls, l, mid), build(rs, mid + 1, r);
        pushup(u);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i ++ ) 
    {
        cin >> p[i].x >> p[i].y;
        xs.push_back(p[i].x);
    }
    sort(xs.begin(), xs.end()); // 离散化
    xs.erase(unique(xs.begin(), xs.end()), xs.end()); 
    for (int i = 0; i < n; i ++ )
    {
        p[i].x = lower_bound(xs.begin(), xs.end(), p[i].x) - xs.begin();
        down[p[i].x] ++ ; // 当前列的down加1
    }
    sort(p, p + n, [&](pii a, pii b) {
        if (a.y != b.y) return a.y < b.y;
        else return a.x < b.x;
    }); // 按y从小到大排序
    build(1, 0, xs.size() - 1); // 初始化线段树

    for (int i = 0; i < n; i ++ )
    {
        int j = i;
        while (j < n && p[j].y == p[i].y) // 求出每一行的右端点j
        {
            down[p[j].x] -- , up[p[j].x] ++ ; // 离开这一行后，up+1,down-1
            update(1, p[j].x);
            j ++ ;
        }
        for (int k = i; k < j - 1; k ++ ) // 对于这一行的点，查询每两个点的区间的最大值
        {
            auto t = query(1, p[k].x + 1, p[k + 1].x - 1);
            best = max(best, min({t.x, k - i + 1, j - k - 1}));
        }
        i = j - 1;
    }
    if (q == 1) cout << best;
    else 
    {
        int res = 0;
        memcpy(down, up, sizeof up); // 做完一次后，up和down颠倒
        memset(up, 0, sizeof up);
        build(1, 0, xs.size() - 1); // bug3 需要重新初始化线段树，将所有结点的u,v置成0
        for (int i = 0; i < n; i ++ )
        {
            int j = i;
            while (j < n && p[j].y == p[i].y) 
            {
                down[p[j].x] -- , up[p[j].x] ++ ;
                update(1, p[j].x);
                j ++ ;
            }
            for (int k = i; k < j - 1; k ++ )
            {
                if (k - i + 1 < best || j - k - 1 < best) continue;
                auto t = query(1, p[k].x + 1, p[k + 1].x - 1); // 区间查询，这里要找区间和
                res += t.y;
            }
            i = j - 1;
        }
        cout << res;
    }
    return 0;
}
