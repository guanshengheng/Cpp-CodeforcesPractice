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
    int ans=0;
    for (int i = 2; i <= n; i++)
    {
        set<int> s;
        int mx = a[i];
        int cnt=0;
        for (int j = i; j >= 1; j--)
        {
            auto it = s.find(a[j]);
            if (it != s.end())
            {
                break;
            }
            if (it == s.end())
            {
                s.insert(a[j]);
                mx = max(mx, a[j]);
            }
            if(mx==i-j+1){
                cnt=mx;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
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