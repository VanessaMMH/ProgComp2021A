#include<bits/stdc++.h>
using namespace std;

/*
link:https://www.beecrowd.com.br/judge/en/problems/view/1566
*/

int main(int argc, char const *argv[])
{

    
    long n;
    int value,entradas;
    vector<int> v;
    cin >> entradas;
    while (entradas--)
    {
        cin>> n;
        v.clear();
        // map <long ,int> mp ;
        for(long i=0;i<n;i++){     
            cin >> value ;
            v.push_back(value);
        }
        sort(v.begin(), v.end());
        for(auto t:v){
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}