#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/pairingsocks
*/

void  pairingSock(stack <char> pila){
    stack <char> aux;
    int n=pila.size();
    int pivot = -1;
    int i = 0;
    while(i<n)
    {
        if(pivot==-1)
        {
            aux.push(pila.top());
            pila.pop();
            i++;    
            pivot++;
            
        }
        else
        {
            if(aux.top()==pila.top())
            {
                i++;
                pivot--;              
            }
            else
            {
            aux.push(pila.top());
            pila.pop();
                i++;
                pivot++;
                
            }
        }
    }       
    if(pivot==-1)  cout << n ; 
    else  cout << "impossible";
}



int main(int argc, char const *argv[])
{
    stack <char> pila , aux;
    int n;
    cin>>n;   
    int i,value;
    n*=2;

    for(i=0; i<n; i++)
    {
        cin >> value;
        pila.push(value);
    }

    pairingSock( pila);

    return 0;
}
