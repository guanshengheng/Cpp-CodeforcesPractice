#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int q;
    cin >> q;

    priority_queue<int> l;

    priority_queue<int, vector<int>, greater<int>> r;
    while (q--)
    {
        char f;
        cin >> f;

        if (f == '+')
        {
            int x;
            cin >> x;

            if (l.empty() || x <= l.top())
            {
                l.push(x);
            }
            else
            {
                r.push(x);
            }

            if (l.size() > r.size() + 1)
            {
                r.push(l.top());
                l.pop();
            }
            else if (r.size() > l.size())
            {
                l.push(r.top());
                r.pop();
            }
        }
        else if (f == '?')
        {
            cout << l.top() << "\n";
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