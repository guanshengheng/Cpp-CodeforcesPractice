#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//dij模板题
//邻接表存图，优先队列找当前距离最小的节点
//如果邻居有被松弛，则也pop进优先队列

int n, m, s;
vector<pair<int, int>> g[111111];
int dis[111111];
bool vis[111111];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
}
void solve()
{
    cin >> n >> m >> s;
    init();

    pq.push({dis[s], s});

    while (!pq.empty())
    {
        auto tp = pq.top();
        pq.pop();
        if (vis[tp.second])
            continue;
        vis[tp.second] = true;
        for (int i = 0; i < g[tp.second].size(); i++)
        {
            if (dis[tp.second] + g[tp.second][i].second <= dis[g[tp.second][i].first])
            {
                dis[g[tp.second][i].first] = dis[tp.second] + g[tp.second][i].second;
                pq.push({dis[g[tp.second][i].first], g[tp.second][i].first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}