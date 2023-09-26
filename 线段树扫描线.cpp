#include <bits/stdc++.h>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
using ll = long long;
using pii = pair<int, int>;

#define ls (u << 1)
#define rs (u << 1 | 1)
const int N = 2e5 + 10;
struct Line 
{
    int x1, x2, y;
    int tag;
    bool operator < (Line &t) 
    {
        return y < t.y;
    }
}lines[N];
struct Tree 
{
    int l, r;
    int cnt, len;
}tree[N * 8];
int xs[N];

void build(int u, int l, int r)
{
    tree[u] = {l, r, 0, 0};
    if (l == r) return;
    else
    {
        int mid = l + r >> 1;
        build(ls, l, mid), build(rs, mid + 1, r);
    }
}

void pushup(int u)
{
    int l = tree[u].l, r = tree[u].r;
    if (tree[u].cnt) tree[u].len = xs[r + 1] - xs[l];
    else tree[u].len = tree[ls].len + tree[rs].len;
}

void modify(int u, int l, int r, int tag)
{
    if (l > tree[u].r || r < tree[u].l) return;
    if (l <= tree[u].l && tree[u].r <= r) 
    {
        tree[u].cnt += tag;
        pushup(u);
        return;
    }
    else
    {
        modify(ls, l, r, tag);
        modify(rs, l, r, tag);
        pushup(u);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {x1, x2, y1, 1};
        lines[n + i] = {x1, x2, y2, -1};
        xs[i] = x1, xs[n + i] = x2;
    }

    n *= 2;
    sort(lines + 1, lines + n + 1);
    sort(xs + 1, xs + n + 1);
    int ed = unique(xs + 1, xs + n + 1) - xs - 1;
    build(1, 1, ed - 1);

    ll ans = 0;
    for (int i = 1; i < n; i ++ )
    {
        int l = lower_bound(xs + 1, xs + ed + 1, lines[i].x1) - xs;
        int r = lower_bound(xs + 1, xs + ed + 1, lines[i].x2) - xs;
        modify(1, l, r - 1, lines[i].tag);
        ans += (ll)tree[1].len * (lines[i + 1].y - lines[i].y);
    }
    cout << ans;
    return 0;
}
