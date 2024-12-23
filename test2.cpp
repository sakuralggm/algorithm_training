#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int N = 110;
int a[N], b[N], backup[N], n;

bool isInsert()
{
    bool flag = false;
    for (int i = 2; i <= n; i ++ )
    {
        a[0] = a[i];
        int pos = i - 1;
        while (a[pos] > a[0]) a[pos + 1] = a[pos], pos -- ;
        a[pos + 1] = a[0]; 
        if (flag) return true;
        if (equal(b + 1, b + n + 1, a + 1)) flag = true;
    }
    return false;
}

void down(int u, int sz)
{
    int t = u;
    if (u * 2 <= sz && a[u * 2] > a[t]) t = 2 * u;
    if (u * 2 + 1 <= sz && a[u * 2 + 1] > a[t]) t = 2 * u + 1;
    if (u != t)
    {
        swap(a[u], a[t]);
        down(t, sz);
    }
}

bool isHeap()
{
    memcpy(a, backup, sizeof a);
    bool flag = false;
    for (int sz = n; sz >= 2; sz -- )
    {
        if (sz == n)
        {
            for (int j = sz / 2; j; j -- )
                down(j, sz);
        }
        else down(1, sz);
        if (flag) return true;
        if (equal(b + 1, b + n + 1, a + 1)) flag = true;
        swap(a[1], a[sz]);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    memcpy(backup, a, sizeof a);
    // if (isInsert()) cout << "Insertion Sort\n";
    if (isHeap()) cout << "Heap Sort\n";

    bool isfirst = true;
    for (int i = 1; i <= n; i ++ )
    {
        if (isfirst) cout << a[i], isfirst = false;
        else cout << ' ' << a[i];
    }
    return 0;
}