#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5005][5005];
ll a[5005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = a[i] * n;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            int k = n - len + 1;
            dp[i][j] = max(a[i] * k + dp[i + 1][j],
                           a[j] * k + dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}