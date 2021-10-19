#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/downtime


7 2
1000
1010
1500
1999
2000
2010
2999


*/


int disastrous(map <int, int >& mp , int k){
    int acum=0 ,i=0 ;
    double value;
    vector <int> vec(mp.size(),0);

    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        acum+= itr->second;
        vec[i]=acum;
        i++;
    }
  
    // for (int v : vec)
    //     cout << v <<" ";

    sort(vec.begin(), vec.end()); 
    value = vec[ vec.size()-1];
    return ceil(value/k);
    

}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, k;
    int pos;
    
    map <int, int > mp;

    cin >> n >> k;

    for(int i=0;i<n;i++){     
        cin >> pos ;
        mp[pos]++;
        mp[pos+1000]--;
    }
    cout << disastrous( mp , k);
    

    return 0;
}