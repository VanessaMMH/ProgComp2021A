#include <bits/stdc++.h>
using namespace std;

#define INF 100000



int tree_size(int n)
{
    return pow(2, ceil(log2(n)) + 1);
}

void build_segment_tree(vector<int> &ar, vector<int> &tree, int left, int right, int pos)
{
    if (left == right)
    {
    tree[pos] = ar[left];
    return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(ar, tree, left, mid, 2 * pos + 1);
    build_segment_tree(ar, tree, mid + 1, right, 2 * pos + 2);
    tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int min_interval(vector<int> &tree, int left, int right, int qleft, int qright, int pos)
{
    if (qleft <= left && qright >= right)
        return tree[pos];
    if (qleft > right || qright < left)
        return INF;
    int mid = (left + right) / 2;
    return min(min_interval(tree, left, mid, qleft, qright, 2 * pos + 1), min_interval(tree, mid + 1, right, qleft, qright, 2 * pos + 2));
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    map<char, int> dict;
    dict.insert({'A', 1});
    dict.insert({'C', 2});
    dict.insert({'G', 3});
    dict.insert({'T', 4});

    vector<int> values(S.size());
    for (int i = 0; i < S.size(); i++)
    values[i] = dict[S[i]];
    vector<int> tree(tree_size(values.size()));
    build_segment_tree(values, tree, 0, values.size() - 1, 0);
    vector<int> answers(P.size());
    for (int i = 0; i < P.size(); i++)
    {
    answers[i] = min_interval(tree, 0, values.size() - 1, P[i], Q[i], 0);
    }
    return answers;
}

int main()
{
    string S = "CAGCCTA";
    vector<int> P = {2, 5, 0};
    vector<int> Q = {4, 5, 6};

    vector<int> ans = solution(S, P, Q);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}