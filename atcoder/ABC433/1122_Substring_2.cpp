#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//调试时要注意边界情况
void solve()
{
    string s;
    cin >> s;
    int l = s.size();
    int ans = 0;
    for (int i = 0; i < l - 1; i++)
    {
        if (s[i] + 1 == s[i + 1])
        {
            int x = i;
            int y = i + 1;
            int cntx = 0;
            while (x >= 0)
            {
                if (s[x] == s[i])
                {
                    x--;
                    cntx++;
                }
                else
                    break;
            }
            int cnty = 0;

            while (y < l)
            {
                if (s[y] == s[i+1])
                {
                    y++;
                    cnty++;
                }
                else
                    break;
            }
            ans += min(cntx, cnty);
        }
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