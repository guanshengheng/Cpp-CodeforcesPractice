#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//邻接表存图
//bfs遍历并黑白染色
//循环处理询问
void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color(n + 1, -1);
    queue<int> que;
    color[1] = 0;
    que.push(1);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : g[u])
        {
            if (color[v] == -1)
            {
                color[v] = color[u] ^ 1;
                que.push(v);
            }
        }
    }

    while (q--)
    {
        int c, d;
        cin >> c >> d;
        if (color[c] == color[d])
        {
            cout << "Town" << endl;
        }
        else
        {
            cout << "Road" << endl;
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