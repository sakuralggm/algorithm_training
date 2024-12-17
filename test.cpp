#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        f = ch != '-';
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f ? x : -x;
}
int n;
bitset<110> a[110];
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    for (int i = 1; i <= n; i++)
        cout << a[i] << "\n";
    for (int j = 1; j <= n; j++)//注意j循环在i循环外
        for (int i = 1; i <= n; i++)
            if (a[i][j])
                a[i] |= a[j];//bitset也挺好写的
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            putchar(a[i][j] + '0'), putchar(' ');
        putchar('\n');
    }
    return 0;
}