#include <bits/stdc++.h>
using namespace std;

/*
Tamaño del subarreglo contiguo más pequeño con una suma mayor o igual a k
*/

int max_Len(vector<int>& v, int k)
{
    map<int,int> m;
    m[0] =0;
    int suma = 0, cont = 0;
    for(int i = 0; i < v.size(); i++)
    {
        suma += v[i];
        if(m.count(suma-k))
        cont = max(cont, i - m[suma-k]);
        if(m.count(suma)==0)
        m[suma] = i;
    }
    return cont;
}
int main(int argc, char const *argv[])
{
    vector <int> v1= {2, 4, 2, 5, 1};
    cout << max_Len(v1,7) << endl;
    
    return 0;
}
