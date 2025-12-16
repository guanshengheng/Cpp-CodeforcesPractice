#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector<int> l(n + 1);
    vector<int> r(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }

    for (int i = n; i > 1; i--)
    {
        r[i - 1] = min(r[i - 1], r[i] - (d[i] == 1));
        l[i - 1] = max(l[i - 1], l[i] - (d[i] !=0));
    }
    int h = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == -1)
        {
            if (h < l[i])
                d[i] = 1;
            if (h + 1 > r[i])
                d[i] = 0;
            if(d[i]<0)
                d[i] = 0;
        }
        if (d[i] == 1)
            h++;
        if (h < l[i] || h > r[i])
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << endl;
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