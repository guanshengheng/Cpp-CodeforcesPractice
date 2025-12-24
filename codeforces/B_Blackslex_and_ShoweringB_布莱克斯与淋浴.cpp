#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += abs(a[i] - a[i - 1]);
    }
    vector<int> b(n + 1);
    int mx = -1e9;
    int mxp = -1;
    b[1] = abs(a[2] - a[1]);
    b[n] = abs(a[n] - a[n - 1]);
    for (int i = 2; i < n; i++)
    {
        b[i] = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i - 1]);
    }
    for (int i = 1; i <= n; i++)
        mx = max(mx, b[i]);
    ans -= mx;
    cout << ans << endl;
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