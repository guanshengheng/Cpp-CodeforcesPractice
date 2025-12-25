#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string k;
    cin >> k;
    int len = k.size();
    int pt1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (k[i] == '1')
        {
            pt1 = i;
            break;
        }
    }

    int pt = n - len + pt1;
    int x = 1;
    int tep = 1;
    for (int i = pt1 - 1; i >= 0; i--)
    {
        if (k[i] == '1')
            x = (x + tep) % 3;
        tep = 3 - tep;
    }
    if (pt % 2)
    {
        if (x == 1)
            cout << "A B" << endl;
        if (x == 2)
            cout << "B C" << endl;
        if (x == 0)
            cout << "C A" << endl;
    }
    else
    {
        if (x == 1)
            cout << "A C" << endl;
        if (x == 2)
            cout << "C B" << endl;
        if (x == 0)
            cout << "B A" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}