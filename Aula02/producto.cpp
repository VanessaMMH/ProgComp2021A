#include <iostream>
#include <vector>
using namespace std;

void printVector(vector <int> vec){
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec.at(i) << " ";
    }
}

int  productoMayor(vector <int> vec){
    int mayor1=1, mayor2=1, producto;
    for (size_t i = 1; i < vec.size(); ++i) {        
        if (vec.at(i)> mayor1){
            mayor2=mayor1;
            mayor1 = vec.at(i);  
        }         
    }
   // cout << mayor1 <<" "<< mayor2;
    return mayor1*mayor2;

}

int main()
{
    int nro_elementos=3;
    vector <int > vec1={1,2,3};
    int mayor=1;
    vector <int > vec2={8,1,6,3,4,10,3,9,14,2};
    cout << productoMayor(vec1);

    return 0;
}