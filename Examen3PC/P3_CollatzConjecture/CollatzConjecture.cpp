#include <bits/stdc++.h>
using namespace std;

/*
link:  https://open.kattis.com/problems/collatz
*/

vector<long long> getSequence(long long n)
{
    vector<long long> vec;
    vec.push_back(n);
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        vec.push_back(n);
    }
    return vec;
}

long long search(vector<long long> vec, long long n)
{
    for (long long i = 0; i < vec.size(); i++)
    {
        if (vec[i] == n)
            return i;
    }
    return -1;
}

void colatzConjecture(long long A, long long B)
{
    vector<long long> seqA, seqB;
    seqA = getSequence(A);
    seqB = getSequence(B);

    long long i, j;
    for (i = 0; i < seqA.size(); i++)
    {
        j = search(seqB, seqA[i]);
        if (j != -1)
            break;
    }

    cout << A << " needs " << i << " steps, " 
    << B << " needs " << j << " steps, they meet at " << seqA[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long A, B;
    while (cin >> A >> B)
    {
        if (A == 0 && B == 0)
            return 0;
        colatzConjecture(A, B);
    }
    return 0;
}