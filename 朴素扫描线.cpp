#include <bits/stdc++.h>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define x first 
#define y second
using ll = long long;
using pii = pair<int, int>;

const int N = 110;
pii l[N], r[N];
int n;
vector<int> xs;

int range_area(int a, int b)
{
    vector<pii> segs;
    for (int i = 0; i < n; i ++ )
    {
        if (l[i].x <= a && r[i].x >= b)
            segs.emplace_back(l[i].y, r[i].y);
    }
    int res = 0;
    int st = -2e9, ed = -2e9;
    sort(segs.begin(), segs.end());
    for (int i = 0; i < segs.size(); i ++ )
    {
        if (segs[i].x <= ed) ed = max(ed, segs[i].y);
        else
        {
            res += ed - st;
            st = segs[i].x, ed = segs[i].y;
        }
    }
    res += ed - st;
    return res * (b - a);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> l[i].x >> l[i].y >> r[i].x >> r[i].y;
        xs.push_back(l[i].x), xs.push_back(r[i].x);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ll res = 0;
    for (int i = 0; i < xs.size() - 1; i ++ )
    {
        res += range_area(xs[i], xs[i + 1]);
    }
    cout << res;
    return 0;
}
