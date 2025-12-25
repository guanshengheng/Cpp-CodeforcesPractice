#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int inf=1e18;
//01背包模板
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n + 1);
    vector<int> h(n + 1);
    vector<int> b(n + 1);
    vector<int> q(n + 1);
    int sw = 0;
    int sb = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> h[i] >> b[i];
        sw += w[i];
        sb += b[i];
        q[i] = h[i] - b[i];
    }
    int x = sw / 2;
    // vector<vector<int>> bg(n + 1, vector<int>(x+1, 0));
    vector<int>dp(x+1,-inf);
    // bg[0][0] = 0;
    dp[0]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= w[i]; j--)
        {
            if (dp[j-w[i]]>-inf)
            {
                dp[j]=max(dp[j],dp[j-w[i]]+q[i]);   
            }
        }
    }
    int max_val = 0;
    for(int i = 0; i <= x; i++) {
        max_val = max(max_val, dp[i]);
    }
    cout << max_val + sb << endl;
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