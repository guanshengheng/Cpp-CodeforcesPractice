#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int x = (1LL << n) - 1;
    // map<int, int> mp;
    int mx = x;
    cout << x << " ";

    for (int i = n - 1; i >= 0; i--)
    {

        x = x & (~(1 << i));
        cout << x << " ";
        vector<int> tp;
        for (int j = i + 1; j < n; j++)
        {
            tp.push_back(j);
        }
        int m = tp.size();
        for (int k = 1; k < (1LL << m); k++)
        {
            int v = x;
            for (int j = 0; j < tp.size(); j++)
            {
                if ((k >> j) & 1)
                {
                    v = v | (1 << tp[j]);
                }
            }
            cout << v << " ";
            // mp[v]++;
        }
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