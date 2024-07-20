// https://pintia.cn/problem-sets/1796449784755585024/exam/problems/type/7?problemSetProblemId=1796449784843665433&page=0
// 参考：https://blog.csdn.net/viVi_beea/article/details/119759026

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
vector<pii> g[N], rg[N];
int in[N], ve[N], vl[N], e[N], l[N], rin[N];

int n, m;
vector<int> top;

struct TASK {
    int a, b, w;
};

vector<TASK> tasks;
int total, lastest;

bool topsort() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }

    while (q.size()) {
        auto h = q.front();
        q.pop();
        top.push_back(h);
        for (auto i : g[h]) {
            int to = i.first, w = i.second;
            ve[to] = max(ve[to], ve[h] + w);
            if (--in[to] == 0) {
                q.push(to);
            }
        }
    }
    if (top.size() == n) {
        total = 0, lastest = 1; // 时间是最大的ve，这个点也是最后一个点，它的vl = ve
        for (int i = 1; i <= n; i++) {
            if (ve[i] > total) {
                total = ve[i];
                lastest = i;
            }
        }
        return true;
    } else {
        return false;
    }
}

void rtopsort() {
    queue<int> q;
    memset(vl, 0x3f, sizeof vl);
    vl[lastest] = ve[lastest];
    for (int i = 1; i <= n; i++) {
        if (!rin[i]) {
            q.push(i);
        }
    }

    while (q.size()) {
        auto h = q.front();
        q.pop();
        for (auto i : rg[h]) {
            int to = i.first, w = i.second;
            vl[to] = min(vl[to], vl[h] - w);
            if (--rin[to] == 0) {
                q.push(to);
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        rg[b].push_back({a, w});
        tasks.push_back({a, b, w});
        in[b]++;
        rin[a]++;
    }
    auto isvalid = topsort();
    if (!isvalid) {
        cout << 0;
    } else {

        rtopsort();

        vector<TASK> ans;
        for (int i = 0; i < tasks.size(); i++) {
            int a = tasks[i].a, b = tasks[i].b, w = tasks[i].w;
            if (ve[a] == vl[b] - w) {
                ans.push_back({a, b, i});
            }
        }
        sort(ans.begin(), ans.end(), [&](TASK &u, TASK &v) {
           if (u.a != v.a) {
                return u.a < v.a;
            } else {
                return u.w > v.w;
            }
        });
        cout << total << "\n";
        for (int i = 0; i < ans.size(); i++) {
            int a = ans[i].a, b = ans[i].b;
            cout << a << "->" << b << "\n";
        }
    }
    return 0;
}
