#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e6 + 5;
int fa[MX];
int siz[MX];
int stk[MX];
int find(int x)
{
    int cnt = 0;
    while (fa[x] != x)
    {
        stk[++cnt] = x;
        x = fa[x];
    }
    while (cnt)
    {
        fa[stk[cnt--]] = x;
    }
    return x;
}
bool isSameSet(int a, int b)
{
    return find(a) == find(b);
}
void Union(int a, int b)
{
    if (isSameSet(a, b))
        return;
    if (siz[a] <= siz[b])
    {
        siz[b] += siz[a];
        fa[find(a)] = find(b);
    }
    else
    {
        siz[a] += siz[b];
        fa[find(b)] = find(a);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
    while (m--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int x, y;
            cin >> x >> y;
            if (isSameSet(x, y))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
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