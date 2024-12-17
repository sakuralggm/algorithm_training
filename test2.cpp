#include <bits/stdc++.h>
using namespace std;
int n;
bitset<110> a[110];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bool x;
            cin >> x;
            cout << x << "\n";
            a[i][j] = x;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j])
                a[i] |= a[j]; // 好好体会位运算
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] + '0' << ' ';
        }
        cout << endl;
    }
    return 0;
}