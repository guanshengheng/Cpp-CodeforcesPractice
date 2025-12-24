#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string k;
    cin >> k;

    int len = k.size();
    int lp = -1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (k[i] == '1')
        {
            lp = i;
            break;
        }
    }
    int pt = lp + (n - len);
    int ans = 1;
    int p2 = 1;
    for (int i = lp - 1; i >= 0; i--)
    {
        if (k[i] == '1')
        {
            ans = (ans + p2) % 3;
        }
        p2 = (p2 * 2) % 3;
    }
    if (pt % 2 != 0)
    {
        if (ans == 1)
            cout << "A B" << endl;
        else if (ans == 2)
            cout << "B C" << endl;
        else
            cout << "C A" << endl;
    }
    else
    {
        if (ans == 1)
            cout << "A C" << endl;
        else if (ans == 2)
            cout << "C B" << endl;
        else
            cout << "B A" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}