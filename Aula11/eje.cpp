#include<bits/stdc++.h>
using namespace std;

// int main(int argc, char const *argv[])
// {

//     map <long , vector <int>> mp ;
//     long n;
//     int value,entradas;
//     cin >> entradas;
//     while (entradas--)
//     {
//         cin>> n;
//         for(long i=0;i<n;i++){     
//             cin >> value ;
//             mp[n].push_back(value);
//         }
//         sort(mp[n].begin(), mp[n].end());
//         for(auto t:mp[n]){
//             cout << t << " ";
//         }
//         cout << endl;
//     }
//     return 0;
//}


int main(int argc, char const *argv[])
{

    
    long n;
    int value,entradas;
    cin >> entradas;
    while (entradas--)
    {
        cin>> n;
        map <long ,int> mp ;
        for(long i=0;i<n;i++){     
            cin >> value ;
            auto it = mp.find(value);
            if (it != mp.end())
                mp[value]++;
            else
                mp[value]=0;
        }
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            cout  << itr->first << ' ';
            if (itr->second >0){
                itr->second--;
                itr--;
            }            
        }
        cout << endl;
    }
    return 0;
}