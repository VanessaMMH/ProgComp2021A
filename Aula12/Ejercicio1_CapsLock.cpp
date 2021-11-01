
#include <bits/stdc++.h>
using namespace std;
/*
Caps Lock
Está enviando un mensaje a un amigo con un teclado especial.
 El teclado solo acepta letras minúsculas y las almacena en un búfer.
 Cuando se presiona la tecla @, alterna la tecla Bloq Mayús:
 todas las letras en el búfer tienen sus mayúsculas invertidas, 
 así como todas las pulsaciones de teclas posteriores.
 Cuando se presiona la tecla $, se vacía todo el búfer. 
Dadas algunas pulsaciones de teclas: muestra el mensaje resultante.

Input:
abc$d@ef$@g$
Output: abcDEFg

*/

string capsLock(string s){
    string output="";
    int flag = -1; 
    queue<char> myqueue;
    for(auto cad:s){
         if(cad=='$'){
            int n=myqueue.size();
            for(char j=0;j<n;j++){
                output += flag == 1 ? toupper(myqueue.front())
                :tolower(myqueue.front());
                myqueue.pop();
            }
        }
        else if(cad=='@')
            flag*=-1;
        else   
            myqueue.push(cad);
    }

    return output;
}

int main(){

    string s = "abc$d@ef$@g$";
    cout << capsLock(s);
    return 0;
}