#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int MOD = 998244353;
const int MX = 1000005;
ll fac[MX], inv[MX];

ll ksm(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 1; i < MX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MX - 1] = ksm(fac[MX - 1], MOD - 2);
    for (int i = MX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll Com(ll n, ll m)
{
    if (m < 0 || m > n)
        return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void solve()
{
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int dx = xb - xa;
    int dy = yb - ya;
    int dy2 = yb + ya;
    if (dx < 0 || dx < abs(dy) || (dx - dy) % 2 || (yb > 0 && ya < 0) || (yb < 0 && ya > 0) || ya == 0 || yb == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (ya < 0 && yb < 0)
    {
        ya = -ya;
        yb = -yb;
        dy = yb - ya;
        dy2 = yb + ya;
    }
    int k1 = (dx + dy) / 2;
    int k2 = (dx + dy2) / 2;
    ll ans = ((Com(dx, k1)) % MOD - (Com(dx, k2)) % MOD + MOD) % MOD;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}