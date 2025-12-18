#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int l, r;
    cin >> l >> r;
    int len = 0;
    int tepl = l;
    while (tepl)
    {
        tepl /= 10;
        len++;
    }
    vector<int> al(len + 1);
    vector<int> ar(len + 1);
    for (int i = len; i >= 1; i--)
    {
        int tp = i;
        int tl = l;
        int tr = r;
        int d = 1;
        while (--tp)
        {
            d *= 10;
        }
        tl /= d;
        tr /= d;
        tl %= 10;
        tr %= 10;
        al[i] = tl;
        ar[i] = tr;
    }
    // bool fg = true;
    int cnt = 0;
    if (len == 1)
    {
        if (r - l >= 2)
            cout << 0 << endl;
        if (r - l == 1)
            cout << 1 << endl;
        if (r == l)
            cout << 2 << endl;
        return;
    }
    int bl = al[len], br = ar[len];
    for (int i = len - 1; i >= 1; i--)
    {
        if (br - bl >= 2)
        {
            break;
        }
        if (br == bl)
        {
            cnt += 2;
        }
        if (br - bl == 1)
        {
            cnt += 1;
        }
        bl *= 10;
        br *= 10;
        bl += al[i];
        br += ar[i];
    }
    if (br == bl)
    {
        cnt += 2;
    }
    if (br - bl == 1)
    {
        cnt += 1;
    }
    cout << cnt << endl;
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