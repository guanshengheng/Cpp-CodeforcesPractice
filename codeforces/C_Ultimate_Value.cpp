
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    vector<ll> c(n + 1);
    vector<ll> d(n + 1, 0);
    vector<ll> e(n + 1, (ll)4e18);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 2 * a[i] - i;
        c[i] = 2 * a[i] + i;
        if (i % 2) sum += a[i];
        else sum -= a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            e[i] = min(e[i - 1], c[i]);
            d[i] = d[i - 1];
        } else {
            e[i] = e[i - 1];
            d[i] = max(d[i - 1], b[i]);
        }
    }
    ll ans = n - 1 + (n % 2) - 1;
    for (int i = 1; i <= n; i++) {
        if (i % 2) ans = max(ans, d[i - 1] - b[i]);
        else ans = max(ans, c[i] - e[i - 1]);
    }
    cout << ans + sum << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
