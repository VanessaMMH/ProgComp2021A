#include <bits/stdc++.h>
using namespace std;

/*
Dados un número entero de matrices y un entero k, 
devuelve el número de subarreglos no vacíos que tienen una suma divisible por k. 
Una submatriz es una parte contigua de una matriz.
*/

int subarrays_div_k(vector<int>& v, int k) {

    int c=0;
    vector <int> suma;
    for (size_t i = 0; i < v.size(); i++)   
    {
        int acum=0;
       for (size_t j = i   ; j < v.size(); j++)
       {
            acum+=v[j];
            if (acum%k==0)
            {
                //cout << acum << " ";
                c++;
            }
       }       
    }
    return c;
}

int main(int argc, char const *argv[])
{
    vector <int> v ={4,5,0,-2,-3,1};
    cout << subarrays_div_k(v,5);
  
    return 0;
}
