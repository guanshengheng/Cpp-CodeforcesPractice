#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int h[N];
int mem[N];
int n;
int dfs(int i)
{
    if (mem[i] != -1)
        return mem[i];
    if (i == n - 1)
    {
        int res;
        res = abs(h[i + 1] - h[i]) + dfs(i + 1);
        mem[i] = res;
        return res;
    }
    int res;
    res = min(abs(h[i + 1] - h[i]) + dfs(i + 1), abs(h[i + 2] - h[i]) + dfs(i + 2));
    mem[i] = res;
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        mem[i] = -1;
    }
    mem[n] = 0;
    cout << dfs(1) << endl;
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