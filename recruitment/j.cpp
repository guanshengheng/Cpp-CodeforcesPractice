#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int long long
const int N = 1e5 + 5;
int a[N];
int pre[N];
int suf[N];
int tree[N * 4];
// int sum[N * 4];
int add[N * 4];
void up(int i)
{
    tree[i] = max(tree[i * 2], tree[2 * i + 1]);
}
void lazy(int i, int v)
{
    tree[i] += v;
    add[i] += v;
}
void down(int i)
{
    if (add[i])
    {
        lazy(2 * i, add[i]);
        lazy(2 * i + 1, add[i]);
        add[i] = 0;
    }
}
void build(int l, int r, int i)
{
    if (l == r)
    {
        tree[i] = pre[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(l, mid, i * 2);
        build(mid + 1, r, i * 2 + 1);
        up(i);
    }
}
void mdf(int jobl, int jobr, int v, int l, int r, int i)
{
    if (jobl <= l && jobr >= r)
    {
        lazy(i, v);
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        down(i);
        if (jobl <= mid)
        {
            mdf(jobl, jobr, v, l, mid, i * 2);
        }
        if (jobr >= mid + 1)
        {
            mdf(jobl, jobr, v, mid + 1, r, i * 2 + 1);
        }
        up(i);
    }
}
int que(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l && r <= jobr)
    {
        return tree[i];
    }
    int mid = (l + r) / 2;
    down(i);
    int ans = -1;
    if (jobl <= mid)
    {
        ans = max(que(jobl, jobr, l, mid, i * 2), ans);
    }
    if (jobr >= mid + 1)
    {
        ans = max(ans, que(jobl, jobr, mid + 1, r, i * 2 + 1));
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> lst;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    set<int> s1;
    for (int i = 1; i <= n; i++)
    {
        s1.insert(a[i]);
        pre[i] = s1.size();
    }

    set<int> s2;
    for (int i = n; i >= 1; i--)
    {
        s2.insert(a[i]);
        suf[i] = s2.size();
    }

    build(1, n, 1);
    int ans = 0;
    lst[a[1]] = 1;
    for (int i = 2; i < n; i++)
    {
        int pos = lst[a[i]];
        if (pos <= i - 1)
        {
            mdf(max(pos, 1), i - 1, 1, 1, n, 1);
        }
        ans = max(ans, que(1, i - 1, 1, n, 1) + suf[i + 1]);
        lst[a[i]] = i;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}