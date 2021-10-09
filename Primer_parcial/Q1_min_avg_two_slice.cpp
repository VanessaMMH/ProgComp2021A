#include <bits/stdc++.h>
using namespace std;
/*
link: https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
*/


int solution(vector<int> &A)
{
    double minim = 20000;
    int n = A.size();
    int min_idx = -1;
    double t;

    for (int i = 0; i < n - 2; i++)
    {
        double avg1 = (A[i] + A[i + 1]) / 2.;
        double avg2 = (A[i] + A[i + 1] + A[i+2]) / 3.;
        t = min(avg1, avg2);
        if (t < minim)
        {
            minim = t;
            min_idx = i;
        }
    }

    double avg = (A[n-1]+A[n-2])/2.;
    if(avg < minim)
    {
        minim = avg;
        min_idx = n-2;
    }

    return min_idx;
}

int main()
{
    vector<int> A = {4, 2, 2, 5, 1, 5, 8};
    cout << solution(A) << endl;
}
