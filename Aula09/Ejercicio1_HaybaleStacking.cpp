#include <bits/stdc++.h>
using namespace std;

vector <int> diferencia;

int main()
{
    int n, k;
    int posi, posd;
    
    
    cin >> n >> k;
    vector <int> vec(n,0);
    vector <int> diferencia(n,0);
 
    for(int i=0;i<k;i++){
       
        cin >> posi >> posd;
        diferencia[posi-1]+=1;
        diferencia[posd]+=-1;
    }
    int acum=0 , value;
    for (size_t i = 0; i < n; i++)
    {
       value=diferencia[i];
        // cout <<diferencia[i] <<" "; 
        acum+=value;
        vec[i]=acum;
    }
    
    sort(vec.begin(), vec.end());
    for (int v : vec)
        cout << v;
    
    cout << "\n"<<vec[n/2] << endl;
    
    return 0;
}