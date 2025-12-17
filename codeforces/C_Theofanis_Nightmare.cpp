#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[n] = a[n];
    int s=a[n];
    for (int i = n - 1; i > 0; i--)
    {
        f[i] = max(f[i+1] + a[i], f[i+1] + a[i] + s);
        s +=a[i];
    }
    cout<<f[1]<<endl;
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