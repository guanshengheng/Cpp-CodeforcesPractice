#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 拆分联通块
// 将数组拆分成左右两部分，如果有前一段最小值还大于后一段最大值则说明该数组不能联通
//记录每次最小值更新的下标，根据其进行了分块
//每个块内都小于块里第一个元素，每个块之间又都小于它后面最大的元素
//实现了联通
void solve()
{
    int n;
    cin >> n;
    vector<int> ml(n + 1);
    vector<int> mr(n + 1);
    vector<int> mlp(1, 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    ml[1] = p[1];
    for (int i = 2; i <= n; i++)
    {
        if (p[i] < ml[i - 1])
        {
            mlp.push_back(i);
            ml[i]=p[i];
        }
        else
        {
            ml[i] = ml[i - 1];
        }
    }
    mr[n] = p[n];
    for (int i = n - 1; i > 0; i--)
    {
        mr[i] = max(mr[i + 1], p[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (ml[i] > mr[i + 1])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    int curl = mlp[0];
    int nptr = 1;
    for (int i = 2; i <= n; i++)
    {
        if (nptr < mlp.size() && i == mlp[nptr])
        {
            curl = mlp[nptr];
            nptr++;
        }
        else
        {
            cout << p[curl] << " " << p[i] << endl;
        }
    }
    for (int i = 0; i < mlp.size() - 1; i++)
    {
        cout << p[mlp[i]] << " " << mr[mlp[i + 1]] << endl;
    }
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