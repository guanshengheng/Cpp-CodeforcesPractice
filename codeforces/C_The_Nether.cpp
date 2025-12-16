#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int l;
    vector<pair<int, int>> r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << "?" << " " << i << " " << n << " ";
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
        cout.flush();
        cin >> l;
        r[i].first = l;
        r[i].second = i;
    }
    sort(r.begin() + 1, r.end(), greater<pair<int, int>>());
    int mxl = r[1].first;
    vector<int> p;
    p.push_back(r[1].second);
    int cnt = 1;
    for (int i = mxl - 1; i > 0; i--)
    {
        while (r[cnt].first == i + 1)
            cnt++;
        while (r[cnt].first == i)
        {
            cout << "? " << p[p.size() - 1] << " " << 2 << "  " << p[p.size() - 1] << " " << r[cnt].second<<endl;
            cout.flush();
            int x;
            cin >> x;
            if (x == 2)
            {
                p.push_back(r[cnt].second);
                break;
            }
        cnt++;

        }
    }
    cout<<"! "<<p.size()<<" ";
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }cout<<endl;
    cout.flush();
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