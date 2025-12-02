#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// dij模板题
// 邻接表存图，优先队列找当前距离最小的节点
// 如果邻居有被松弛，则也pop进优先队列
#define int long long
const int MX = 2e5 + 10;
int n, m;

vector<pair<int, int>> g[MX];
int dis[MX];
bool vis[MX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init()
{
    for (int i = 1; i <= n; i++)
        dis[i] = 1e18 + 7;
    while (m--)
    {
        int u, v, b;
        cin >> u >> v >> b;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }
}
void solve()
{
    cin >> n >> m;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    init();
    dis[1] = A[1];
    pq.push({dis[1], 1});

    while (!pq.empty())
    {
        auto tp = pq.top();
        pq.pop();
        if (vis[tp.second])
            continue;
        vis[tp.second] = true;
        for (int i = 0; i < g[tp.second].size(); i++)
        {
            if (dis[tp.second] + g[tp.second][i].second + A[g[tp.second][i].first] <= dis[g[tp.second][i].first])
            {
                dis[g[tp.second][i].first] = dis[tp.second] + g[tp.second][i].second+A[g[tp.second][i].first];
                pq.push({dis[g[tp.second][i].first], g[tp.second][i].first});
            }
        }
    }
    for (int i = 2; i <= n; i++)
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