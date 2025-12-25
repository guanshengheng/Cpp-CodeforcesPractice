#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int q;
    cin >> q;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    // int cnt = 0;
    while (q--)
    {
        char f;
        cin >> f;
        if (f == '+')
        {
            // cnt++;
            int x;
            cin >> x;

            if (l.empty() || x <= l.top())
                l.push(x);
            else 
                r.push(x);
            while (l.size() > r.size() + 1)
            {
                int y = l.top();
                r.push(y);
                l.pop();
            }
            while (r.size() > l.size() )
            {
                int y = r.top();
                l.push(y);
                r.pop();
            }
        }
        if (f == '?')
        {
            cout << l.top() << endl;
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