#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    if (m < n || m > n * (n + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (m > n - i + 1)
        {
            m -= n - i + 1;
            a[p++] = i;
        }
        else
        {
            for (int j = i; j <= n - m; j++)
            {
                a[p++] = i - 1;
            }
            for (int j = n - m + 1; j <= n; j++)
            {
                a[p++] = i;
            }
            break;
        }
    }
    // sort(a.begin() + 1, a.end());
    ll rub = a[n] + 1;
    ll pre = a[n];
    cout << a[n] << endl;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] == a[i + 1])
        {
            cout << pre << " " << rub << endl;
            pre = rub;
            rub++;
        }
        else
        {
            cout << pre << " " << a[i] << endl;
            pre = a[i];
        }
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