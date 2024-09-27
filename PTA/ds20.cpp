#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string x;
    stack<int> val;
    bool flag = true;

    while (cin >> x, x != "#")
    {
        if (x == "+" || x == "-" || x == "*" || x == "/")
        {
            if (val.size() < 2)
            {
                cout << "Expression Error: " << val.top();
                flag = false;
                break;
            }
            else
            {
                int a = val.top();
                val.pop();
                int b = val.top();
                val.pop();
                if (x == "/" && a == 0)
                {
                    cout << "Error: " << b << "/0";
                    flag = false;
                    break;
                }
                else if (x == "+")
                {
                    val.push(a + b);
                }
                else if (x == "-")
                {
                    val.push(b - a);
                }
                else if (x == "*")
                {
                    val.push(a * b);
                }
                else if (x == "/")
                {
                    val.push(b / a);
                }
            }
        }
        else
        {
            val.push(stoi(x));
        }
    }
    if (flag)
    {
        if (val.size() > 1)
        {
            cout << "Expression Error: " << val.top();
        }
        else
        {
            cout << val.top();
        }
    }
    return 0;
}