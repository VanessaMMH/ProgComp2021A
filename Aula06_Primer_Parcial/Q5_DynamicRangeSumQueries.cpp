#include <bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1648
*/


long long tree_size(long long n)
{
    return pow(2, ceil(log2(n)) + 1);
}

void build_segment_tree(vector<long long> &ar, vector<long long> &tree, long long left, long long right, long long pos)
{
    if (left == right)
    {
        tree[pos] = ar[left];
        return;
    }
    long long mid = (left + right) / 2;
    build_segment_tree(ar, tree, left, mid, 2 * pos + 1);
    build_segment_tree(ar, tree, mid + 1, right, 2 * pos + 2);
    tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

long long sum_interval(vector<long long> &tree, long long left, long long right, long long qleft, long long qright, long long pos)
{
    if (qleft <= left && qright >= right)
        return tree[pos];
    if (qleft > right || qright < left)
        return 0;
    long long mid = (left + right) / 2;
    return sum_interval(tree, left, mid, qleft, qright, 2 * pos + 1) + sum_interval(tree, mid + 1, right, qleft, qright, 2 * pos + 2);
}

void update_interval(vector<long long> &tree, long long left, long long right, long long qpos, long long val, long long pos)
{
    if (qpos < left || qpos > right)
        return;
    tree[pos] += val;
    if (left != right)
    {
        long long mid = (left + right) / 2;
        update_interval(tree, left, mid, qpos, val, 2 * pos + 1);
        update_interval(tree, mid + 1, right, qpos, val, 2 * pos + 2);
    }
}

int main()
{
    long long n, qs;
    cin >> n >> qs;
    vector<long long> ar(n);
    vector<long long> tree(tree_size(ar.size()));
    for (long long i = 0; i < n; i++)
        cin >> ar[i];
    build_segment_tree(ar, tree, 0, ar.size(), 0);
    for (long long i = 0; i < qs; i++)
    {
        long long q, a, b;
        cin >> q >> a >> b;
        if (q == 1)
        {
            update_interval(tree, 0, ar.size(), a - 1, b - ar[a - 1], 0);
            ar[a - 1] = b;
        }
        else
        {
            cout << sum_interval(tree, 0, ar.size(), a - 1, b - 1, 0)
                <<"\n";
        }
    }
}