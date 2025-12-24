#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    int total = 1 << n;
    vector<int> p;
    vector<bool> used(total, false);

    // 1. 为了字典序最小，第一个数选 2^(n-1) - 1
    int first = (1 << (n - 1)) - 1;
    p.push_back(first);
    used[first] = true;

    // 2. 接着从小到大放入所有不包含第 n-1 位（最高位）的数
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        if (!used[i]) {
            p.push_back(i);
            used[i] = true;
        }
    }

    // 3. 放入全 1 的数 2^n - 1，这会保证前缀与的结果在这一步之后依然很大
    int all_ones = (1 << n) - 1;
    if (!used[all_ones]) {
        p.push_back(all_ones);
        used[all_ones] = true;
    }

    // 4. 从小到大放入剩余所有的数（即包含最高位的数）
    for (int i = 0; i < total; ++i) {
        if (!used[i]) {
            p.push_back(i);
            used[i] = true;
        }
    }

    // 输出结果
    for (int i = 0; i < total; ++i) {
        cout << p[i] << (i == total - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return;
}