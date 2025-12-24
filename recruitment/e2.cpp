#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
mt19937_64 rd(time(0));
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    vector<int> rd2(n + 1);
    vector<int> pre2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        rd2[i] = rd();
    }
    pre[1] = a[1] ^ rd2[a[1]];
    pre2[1] = 1 ^ rd2[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i] ^ rd2[a[i]];
        pre2[i] = pre2[i - 1] ^ i ^ rd2[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            int len = i - j + 1;
            if ((pre[i] ^ pre[j - 1]) == pre2[len])
            {
                ans = max(ans, len);
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}