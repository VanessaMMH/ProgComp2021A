
#include <bits/stdc++.h>
using namespace std;

/*
Dado un array que contiene números enteros positivos y negativos. Encuentre
la mayor suma de sus subarrays
*/

int mayor_sum(vector <int> v){
    int mayor_suma = v[0];
    int suma = 0;
    for (int i = 0; i < v.size(); i++){
        suma = suma + v[i];
        if(suma > mayor_suma  )
        {
            mayor_suma = suma;
        }   
        else if(suma < 0)
            suma = 0;
    }
    return mayor_suma;
}
 
int main(){

    vector <int> v= {1,-2, 3, 10, -4, 7, 2, -5};
    cout << mayor_sum(v);    
    return 0;
}