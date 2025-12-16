#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    // 使用 vector 存储 a 和 b，这里用 0-based 索引更方便排序
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // 用于存储区间的 vector，pair 的 first 是左端点，second 是右端点
    vector<pair<int, int>> v(n);
    ll sum = 0; // 注意：总和必须用 long long

    for (int i = 0; i < n; i++)
    {
        // 累加基础长度
        sum += abs(a[i] - b[i]);
        // 规范化区间：左小右大
        v[i] = {min(a[i], b[i]), max(a[i], b[i])};
    }

    // 【关键步骤】排序
    // 排序后，我们只需要比较相邻的区间，就能找到最小间隙
    sort(v.begin(), v.end());

    ll min_add = 3e18; // 初始化为一个巨大的数

    // 遍历相邻的区间
    for (int i = 0; i < n - 1; i++)
    {
        // 计算间隙：后一个的起点 - 前一个的终点
        // 如果结果 < 0，说明重叠，间隙视为 0
        ll gap = max(0, v[i+1].first - v[i].second);
        
        // 代价是间隙的 2 倍
        min_add = min(min_add, gap * 2);
    }

    // 最终答案 = 基础长度 + 最小额外代价
    cout << sum + min_add << endl;
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