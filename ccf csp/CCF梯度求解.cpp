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
const int mod = 1e9 + 7;
int n, m;

ll qmi(ll a, int k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1) res = res * a % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return res % mod;
}

struct Poly
{
    vector<vector<ll>> f;
    Poly(): f{} {}
    Poly(int x)  
    {
        vector<ll> a(n + 1, 0);
        a[0] = x;
        f.push_back(a);
    }
    Poly(string str)
    {
        int ind = stoi(str.substr(1));
        vector<ll> a(n + 1, 0);
        a[0] = 1, a[ind] = 1;
        f.push_back(a);
    }
    Poly operator * (const Poly & w) const
    {
        Poly res;
        for (auto &x : f)
        {
            for (auto &y : w.f)
            {
                vector<ll> t(n + 1, 0);
                t[0] = (x[0] * y[0]) % mod;
                for (int i = 1; i <= n; i ++ ) t[i] = x[i] + y[i];
                res.f.push_back(t);
            }
        }
        return res;
    }
    Poly operator + (const Poly & w) const 
    {
        Poly res;
        res.f = f;
        for (auto &x : w.f) res.f.push_back(x);
        return res;
    }
    Poly diff(int ind)
    {
        Poly res;
        for (auto &x : f) res.f.push_back(x);
        for (auto &vec : res.f)
        {
            vec[0] = (vec[0] * vec[ind]) % mod;
            vec[ind] -- ;
        }
        return res;
    }
    ll eval(vector<int> & v)
    {
        ll sum = 0;
        for (auto &vec : f)
        {
            int res = vec[0];
            if (!res) continue;
            for (int i = 1; i <= n; i ++ )
                res = (res * qmi(v[i - 1], vec[i])) % mod;
            sum = (sum + res) % mod;
        }
        return ((sum % mod) + mod) % mod;
    }
};
stack<Poly> val;

void calc(string str)
{
    Poly a = val.top();
    val.pop();
    Poly b = val.top();
    val.pop();
    if (str == "*") val.push(a * b);
    else if (str == "+") val.push(a + b);
    else
    {
        for (auto &x : a.f) x[0] = -x[0];
        val.push(a + b);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    string formula;
    cin.get();
    getline(cin, formula);
    
    stringstream oss(formula);
    string str;
    while (oss >> str)
    {
        if (str[0] == 'x')
        {
            Poly a(str);
            val.push(a);
        }
        else if (str == "*" || str == "+" || str == "-") calc(str);
        else 
        {
            Poly a(stoi(str));
            val.push(a);
        }
    }
    Poly ff = val.top();
    while (m -- )
    {
        vector<int> t(n, 0);
        int ind;
        cin >> ind;
        for (int i = 0; i < n; i ++ ) cin >> t[i];
        Poly tt = ff.diff(ind);
        cout << tt.eval(t) << "\n";
    }
    return 0;
}
