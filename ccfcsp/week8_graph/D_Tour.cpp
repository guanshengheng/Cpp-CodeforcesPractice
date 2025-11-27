#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//邻接表存图，dfs遍历
vector<int>G[2020];
vector<int>vis(2020);
int ans=0;
void dfs(int x){
    if(vis[x])return;
    vis[x]=true;
    ans++;
    for(int y:G[x]){
        dfs(y);
    }
}
void solve() {
    int n ,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a;
        int b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[j]=false;
        }
        dfs(i);
    }
    cout<<ans<<endl;
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