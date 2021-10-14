#include<iostream>
using namespace std;
/*. 10. Dados dos arrays ordenados A y B con n y m valores respectivamente. Considere que el array A tiene espacio
suficiente para contener a los elementos de B. Escriba una función que copie los elementos de B en A
manteniendo el orden.*/


void copiar_values(int* &a1 , int* &a2 , int longitud){
    a2=new int [longitud];
    
    for (size_t i = 0; i < longitud; i++)
    {
        a2[i]=a1[i];
    }
}

void print_array(int* &a1){
    for (size_t i = 0; i < 3; i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    
}

void add_value(int* &arr, int longitud){
    int value;
    arr=new int [longitud];
    for (size_t i = 0; i < longitud; i++)
    {

        cin >> value;
        arr[i]=value ;
    }
}
int main(int argc, char const *argv[])
{
    int longitud1, longitud2;
    int* a1=nullptr;
    int* a2=nullptr;
    int value;
    cout << "Ingrese tamanho del arreglo" <<endl;
    cin >> longitud1;
    cout << "Ingrese valores del  array" <<endl;
    add_value(a1,longitud1);
    // cout << "Ingrese valores del segundo array" <<endl;
    // add_value(a2,longitud2);
    //cout << sizeof(a1)/sizeof(a1[0]);
    print_array(a1);
    cout << endl;
    copiar_values(a1,a2,longitud1);
    print_array(a2);
   
    
    

    return 0;
}
