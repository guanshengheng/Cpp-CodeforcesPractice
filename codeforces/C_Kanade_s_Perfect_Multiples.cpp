#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    vector<bool> vis(n + 1, false);
    vector<int> b;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            b.push_back(a[i]);
            int pre = a[i];
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] % a[i] == 0)
                {
                    if (a[j] - pre > a[i])
                    {
                        cout << -1 << endl;
                        return;
                    }
                    vis[j] = true;
                    pre = a[j];
                }
                else
                {
                    j = lower_bound(a.begin() +j + 1, a.end(), pre+a[i]) - a.begin() - 1;
                }
            }
            ll g = k / a[i] * a[i];
            if (g != pre)
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << b.size() << endl;
    for (int i : b)
    {
        cout << i << " ";
    }
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