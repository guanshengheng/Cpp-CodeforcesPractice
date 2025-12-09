#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x, y;
    
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 1. 基础参数计算
    ll d = y - x;
    ll r0 = (a[0] * x) % d;

    // 2. 转换问题：计算每个人的区间 [q[i], q[i] + a[i]]
    // q[i] 是将重量 normalized (归一化) 后的步数坐标
    vector<ll> q(n);
    ll L = -2e18; // 全局交集的左端点 (初始化为极小)
    ll R = 2e18;  // 全局交集的右端点 (初始化为极大)

    for(int i = 0; i < n; i++) {
        // 同余检查：如果余数对不上，直接无解
        if ((a[i] * x) % d != r0) {
            cout << -1 << endl;
            return;
        }

        // 计算当前孩子的最小步数 (对应全拿小糖果)
        q[i] = (a[i] * x - r0) / d;

        // 更新全局交集
        // 左边界：所有孩子必须至少达到的步数 (由持有小糖果重量最大的人决定)
        L = max(L, q[i]);
        
        // 右边界：所有孩子至多能达到的步数 (由持有大糖果重量最小的人决定)
        // q[i] + a[i] 对应的是 (a[i]*y - r0)/d
        R = min(R, q[i] + a[i]);
    }

    // 3. 判断交集是否存在
    if (L > R) {
        cout << -1 << endl;
    } else {
        // 4. 计算答案
        // 我们选择 R 作为最终的公共步数，因为它能让大糖果数量最大
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            // (R - q[i]) 正是第 i 个孩子需要的大糖果数量
            // 这里累加不会溢出，因为 ans 最大约为 N * 10^9 = 10^14
            ans += (R - q[i]);
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}