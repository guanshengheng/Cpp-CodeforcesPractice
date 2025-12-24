#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 3e5 + 5;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> g[MX];
    while (m--)
    {
        int a;
        cin >> a;
        vector<int> A(a + 1);
        for (int i = 1; i <= a; i++)
        {
            cin >> A[i];
        }
        int b;
        cin >> b;
        vector<int> B(b + 1);
        for (int i = 1; i <= b; i++)
        {
            cin >> B[i];
        }
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                g[A[i]].push_back(B[j]);
                g[B[j]].push_back(A[i]);
            }
        }
    }
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