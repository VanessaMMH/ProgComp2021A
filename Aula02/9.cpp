#include<iostream>
using namespace std;

/* Escriba una función que genere el numero n de la secuencia Fibonacci*/

int  fibonacci(int n){
    if (n<=1)
    {       
        return n;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
    
}

int main(int argc, char const *argv[])
{
    cout << fibonacci(8) << endl;
    return 0;
}
