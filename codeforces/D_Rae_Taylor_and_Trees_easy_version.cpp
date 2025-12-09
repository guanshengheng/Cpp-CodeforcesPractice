#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//拆分联通块
//将数组拆分成左右两部分，如果有前一段最小值还大于后一段最大值则说明该数组不能联通
void solve()
{
    int n;
    cin >> n;
    vector<int> ml(n + 1);
    vector<int> mr(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    ml[1]=p[1];
    for (int i = 2; i <= n; i++){
        ml[i]=min(ml[i-1],p[i]);
    }
    mr[n]=p[n];
    for(int i=n-1;i>0;i--){
        mr[i]=max(mr[i+1],p[i]);
    }
    for(int i=1;i<n;i++){
        if(ml[i]>mr[i+1]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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