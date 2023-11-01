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
string output, input, byt, str;
int idx, s;
string getByte(int n, int d) // 读n个字节，d=0时后读的拼在后面，d=1时后读的拼在前面（小端序）
{
    string res;
    for (int i = 0; i < n; i ++ )
    {
        if (!d) res += input.substr(idx, 2);
        else res = input.substr(idx, 2) + res;
        idx += 2;
    }
    return res;
}
int getDec(string str) // 把十六进制的字符串化为整数
{
    int res = 0;
    for (auto x : str)
    {
        if (isdigit(x)) x -= '0';
        else x = 10 + x - 'a';
        res = res * 16 + x;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> s;
    s = ceil(s / 8.0);
    for (int i = 0; i < s; i ++ ) cin >> str, input += str;
    // 引导域
    bool isintro = true;
    while (isintro)
    {
        string x = getByte(1, 0);
        int t = getDec(x.substr(0, 1));
        if ((t >> 3 & 1) == 0) isintro = false; 
    }
    // 数据域
    while (idx < input.size())
    {
        byt = getByte(1, 0);
        int first = getDec(byt);
        int type = first % 4;
        if (type == 0) // 字面量
        {
            int L = first / 4;
            if (L <= 59) output += getByte(L + 1, 0);
            else 
            {
                int l;
                if (L == 60) l = getDec(getByte(1, 0));
                else if (L == 61) l = getDec(getByte(2, 1));
                else if (L == 62) l = getDec(getByte(3, 1));
                else if (L == 63) l = getDec(getByte(4, 1));
                output += getByte(l + 1, 0);
            }
        }
        else // 回溯引用
        {
            int l, o, offset;
            if (type == 1) // 回溯引用形式1
            {
                l = first % 32 / 4 + 4;
                o = first / 32 * 256 + getDec(getByte(1, 0));
            }
            else if (type == 2) // 回溯引用形式2
            {
                l = first / 4 + 1;
                o = getDec(getByte(2, 1));
            }
            offset = output.size() / 2 - o;
            if (o >= l) output += output.substr(2 * offset, l * 2);
            else 
            {
                for (int i = 0; i < l / o; i ++ ) output += output.substr(2 * offset, o * 2);
                if (l % o) output += output.substr(2 * offset, (l % o) * 2);
            }
        }
    }
    for (int i = 0; i < output.size(); i += 16)
    {
        for (int j = i; j < output.size() && j < i + 16; j ++ )
            cout << output[j];
        cout << "\n";
    }
    return 0;
}
