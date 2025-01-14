// to_string() map[]注意访问无效ans    diff[]change[]
// dfs 重复则终结
#include <bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int k, ans;
int diff[20], change[20];
string s;
void dfs(string s1)
{
    if (mp[s1])
        return; // 已经存在该字符串无需重复替换规则
    mp[s1] = 1;
    ans++;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < s1.length(); j++)
        {
            if (s1[j] == diff[i])
            {
                string s2 = s1.substr(0, j) + to_string(change[i]) + s1.substr(j + 1);
                dfs(s2);
            }
        }
    }
    return;
}
int main()
{
    cin >> s >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> diff[i] >> change[i];
    }
    dfs(s);
    cout << ans << endl;
    return 0;
}