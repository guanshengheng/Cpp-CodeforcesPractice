#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    ll a, b, r;
    cin >> a >> b >> r;
    if (a > b)
        swap(a, b);
    bool fg = false;
    // ll res1 = 0;
    // ll res2 = 0;
    ll x = 0;
    for (int i = 60; i >= 0; i--)
    {
        ll a2 = a & (1LL << i);
        ll b2 = b & (1LL << i);
        if (a2 != b2)
        {
            if (!fg)
            {
                // res1 = b2;
                // x += b2;
                fg = true;
            }
            // cout<<res1<<endl;
            else
            {
                if (!a2 && x + (1LL << i)<=r)
                {
                    x += (1LL << i);
                    // res2 += (1LL << i);
                    a ^= (1LL << i); // a: 0 -> 1
                    b ^= (1LL << i); // b: 1 -> 0
                }
            }
        }
    }
    cout<<b-a<<endl;
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