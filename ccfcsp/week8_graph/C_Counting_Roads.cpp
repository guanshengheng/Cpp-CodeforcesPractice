#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//水题
void solve() {
    int n;
    int m;
    cin>>n>>m;
    int cnt[n+1];
    for(int i=1;i<=n;i++){
        cnt[i]=0;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}