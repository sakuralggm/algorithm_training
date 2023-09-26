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
    for (int i = 0; i < n; i ++ ) // 寻找与该长条相交的所有区间
    {
        if (l[i].x <= a && r[i].x >= b)
            segs.emplace_back(l[i].y, r[i].y); 
    }
    int res = 0;
    int st = -2e9, ed = -2e9;
    sort(segs.begin(), segs.end()); // 排序
    for (int i = 0; i < segs.size(); i ++ ) // 区间合并，同时每合并出一个新区间就累加它的长度
    {
        if (segs[i].x <= ed) ed = max(ed, segs[i].y);
        else
        {
            res += ed - st;
            st = segs[i].x, ed = segs[i].y;
        }
    }
    res += ed - st;
    return res * (b - a); // 返回该长条的面积
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> l[i].x >> l[i].y >> r[i].x >> r[i].y;
        xs.push_back(l[i].x), xs.push_back(r[i].x); // 保存所有X
    }
    sort(xs.begin(), xs.end()); // 排序
    xs.erase(unique(xs.begin(), xs.end()), xs.end()); // 去重
    ll res = 0;
    for (int i = 0; i < xs.size() - 1; i ++ )
    {
        res += range_area(xs[i], xs[i + 1]); // 计算每个长条的面积相加
    }
    cout << res;
    return 0;
}
