// #define LOCAL
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

vector<pii> points;
set<pii> s;
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> ys;
    vector<int> xs;
    for (int i = 0; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
        xs.push_back(x);
        ys.push_back(y);
        s.insert({x, y});
    }
    // 思路：先对所有y做离散化，然后按照离散化后的y分别对每一行的x做离散化
    sort(ys.begin(), ys.end()); // 1. 排序
    ys.erase(unique(ys.begin(), ys.end()), ys.end()); // 2. 去重
    vector<int> g[ys.size()];
    for (auto p : points)
    {
        int ind = lower_bound(ys.begin(), ys.end(), p.second) - ys.begin(); // 3. 二分取点
        g[ind].push_back(p.first);
    }
    for (int i = 0; i < ys.size(); i ++ ) sort(g[i].begin(), g[i].end()); // 对于排好序的每一行，行中x的下标就是这一行比x小的点的数量
    // 先对所有x做离散化，然后按照离散化后的x分别对每一列的x做离散化
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    vector<int> gg[xs.size()];
    for (auto p : points)
    {
        int ind = lower_bound(xs.begin(), xs.end(), p.first) - xs.begin();
        gg[ind].push_back(p.second);
    }
    for (int i = 0; i < xs.size(); i ++ ) sort(gg[i].begin(), gg[i].end()); // 对于排好序的每一列，行中y的下标就是这一列比y小的点的数量

    map<pii, int> mpp;
    int maxx = 1;
    for (auto x : xs)
    {
        for (auto y : ys)
        {
            if (s.count({x, y})) continue;
            int res = 2e9;
            int indx = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            int yy = upper_bound(gg[indx].begin(), gg[indx].end(), y) - gg[indx].begin();
            int indy = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
            int xx = upper_bound(g[indy].begin(), g[indy].end(), x) - g[indy].begin();
            res = min({(int)gg[indx].size() - yy, yy, xx, (int)g[indy].size() - xx});
            if (res >= maxx) mpp[{x, y}] = res, maxx = res; // 非常重要，每次只保存不劣于当前最优解的情况，可以节省大量内存
        }
    }
    int ans = -2e9;
    for (auto p : mpp)
        ans = max(ans, p.second);
    int cnt = 0;
    for (auto p : mpp)
    {
        if (p.second == ans) 
            cnt ++ ;
    }
    if (q == 1) cout << ans;
    else cout << cnt;
    return 0;
}
