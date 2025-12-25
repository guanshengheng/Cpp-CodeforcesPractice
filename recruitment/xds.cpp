#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long
const int N = 1e5 + 5;
int a[N];
int sum[N * 4];
int add[N * 4];
void up(int i)
{
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}
void lazy(int i, int v, int n)
{
    sum[i] += v * n;

    add[i] += v;
}
void down(int i, int ln, int rn)
{
    if (add[i])
    {
        lazy(i * 2, add[i], ln);
        lazy(i * 2 + 1, add[i], rn);
        add[i] = 0;
    }
}
void build(int l, int r, int i)
{
    if (l == r)
        sum[i] = a[l];
    else
    {
        int mid = (l + r) / 2;
        build(l, mid, i * 2);
        build(mid + 1, r, i * 2 + 1);
        up(i);
    }
    add[i] = 0;
}
void mfy(int jobl, int jobr, int jobv, int l, int r, int i)
{
    if (jobl <= l && r <= jobr)
    {
        lazy(i, jobv, r - l + 1);
    }

    else
    {
        int mid = (l + r) >> 1;
        down(i, mid - l + 1, r - mid);
        if (jobl <= mid)
        {
            mfy(jobl, jobr, jobv, l, mid, i * 2);
        }
        if (jobr > mid)
        {
            mfy(jobl, jobr, jobv, mid + 1, r, i * 2 + 1);
        }
        up(i);
    }
}
int que(int jobl, int jobr, int l, int r, int i)
{
    if (jobl <= l && r <= jobr)
    {
        return sum[i];
    }
    int mid = (l + r) / 2;
    down(i, mid - l + 1, r - mid);
    int ans = 0;
    if (jobl <= mid)
    {
        ans += que(jobl, jobr, l, mid, i * 2);
    }
    if (jobr > mid)
    {
        ans += que(jobl, jobr, mid + 1, r, i * 2 + 1);
    }
    return ans;
}

void solve()
{
    int n = 5;
    // ��ʼ������ a: {1, 2, 3, 4, 5}
    for (int i = 1; i <= n; i++)
        a[i] = i;

    // 1. ����
    build(1, n, 1);
    cout << "��ʼ���� [1, 5] �ĺ�: " << que(1, 5, 1, n, 1) << " (����ֵ: 15)" << endl;

    // 2. �����޸ģ��� [2, 4] ÿ������ 10
    // ԭ������: {1, 12, 13, 14, 5}
    mfy(2, 4, 10, 1, n, 1);
    cout << "�޸ĺ����� [2, 4] �ĺ�: " << que(2, 4, 1, n, 1) << " (����ֵ: 39)" << endl;
    cout << "�޸ĺ����� [1, 5] �ĺ�: " << que(1, 5, 1, n, 1) << " (����ֵ: 45)" << endl;

    // 3. �����ѯ��֤ (��ѯ [3, 3])
    cout << "�޸ĺ��±�Ϊ 3 ��ֵ: " << que(3, 3, 1, n, 1) << " (����ֵ: 13)" << endl;
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