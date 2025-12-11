#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//思维题 
//将所有的不在环内的di都成环所需要的最少的个数就是答案
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> id(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        id[p[i]] = i;
    }

    vector<int> d(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        int x = d[i];
        while (!vis[x])
        {

            vis[x] = true;
            x = id[x];
            ans++;
        }
        cout << ans << " ";
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