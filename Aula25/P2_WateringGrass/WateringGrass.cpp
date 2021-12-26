#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
link: https://open.kattis.com/problems/grass
*/


double N, L, W, x, r;

void distances(vector<pair<double, double>> &stretch, double &L){
    double c = 0, i = 0, aux = 0;
    double n = stretch.size();

    while(true){
        double tmp = -1;
        while(i < n &&  stretch[i].first <= aux){
            tmp = max(tmp, stretch[i].second);
            i++;
        }
        if(tmp == -1){
            cout << -1 << endl;
            return;
        }
        c++;
        aux = tmp;
        if (aux >= L){
            cout << c << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    while(cin >> N >> L >> W){
        vector<pair<double, double>> stretch;
        while(N--){
            cin >> x >> r;
            if (2*r > W){
                double d = sqrt(pow(r, 2) - pow(W/2, 2));
                stretch.push_back(pair<double, double>(x - d, x + d));
            }
        }
        sort(stretch.begin(), stretch.end());
        distances(stretch, L);
    }

    return 0;
}