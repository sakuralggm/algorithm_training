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
using psi = pair<string, int>;
map<string, vector<psi>> dict;
psi get(string &str)
{
    int ind = str.find(":");
    if (ind == string::npos) return psi(str, 0);
    string name = str.substr(0, ind);
    int level = stoi(str.substr(ind + 1));
    return psi(name, level);
}
map<string, map<string, int>> users;
set<string> has_level;
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string str, right, character, name;
    int p, r, u, q, n;
    cin >> p;
    for (int i = 0; i < p; i ++ ) 
    {
        cin >> str;
        int ind = str.find(":");
        if (ind != string::npos) has_level.insert(str.substr(0, ind));
    }
    cin >> r;
    for (int i = 0; i < r; i ++ ) 
    {
        cin >> str >> n;
        vector<psi> v;
        for (int j = 0; j < n; j ++ )
        {
            cin >> right;
            v.push_back(get(right));
        }
        dict[str] = v;
    }
    cin >> u;
    for (int i = 0; i < u; i ++ )
    {
        cin >> str >> n;
        for (int j = 0; j < n; j ++ )
        {
            cin >> character;
            auto rights = dict[character];
            for (auto item : rights)
            {
                auto & t = users[str][item.first]; // 两层不存在，也能返回一个0，map牛逼！
                t = max(t, item.second);
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i ++ )
    {
        cin >> name >> right;
        if (users.count(name))
        {
            psi t = get(right);
            auto & tt = users[name];
            if (has_level.count(right) && tt.count(right)) cout << tt[right] << "\n";
            else if (tt.count(t.first) && t.second >= 0 && t.second <= tt[t.first]) cout << "true\n";
            else cout << "false\n";
        }
        else cout << "false\n";
    }
    return 0;
}
