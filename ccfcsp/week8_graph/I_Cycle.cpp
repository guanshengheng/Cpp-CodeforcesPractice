#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//bfs
//找到1则更新答案
//找到其他未访问的点则更新距离传进队列
//不存在某个点被多次访问的情况


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    const int INF = 1e9;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    int ans = INF;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (v == 1)
            {
                ans = min(ans, dist[u] + 1);
            }
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
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