#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//双指针模板题
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int cnt=0;
    vector<int>a;
    vector<int>b;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int la=a.size();
    int lb=b.size();
    if(a[0]>b[lb-1]){
        cout<<"No"<<endl;
        return;
    }
    
    int pb=0;
    for(int pa=0;pa<la;pa++){
        while(pb<lb){
            if(b[pb]>=a[pa]){
                cnt++;
                pb++;
                break;
            }
            else{
                pb++;
            }
        }
    }
    if(cnt>=k){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }return;
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