#include <bits/stdc++.h>
using namespace std;

/*
Backspace
Está enviando un mensaje a un amigo con un teclado especial.
El teclado solo acepta letras minúsculas.
Cuando se presiona el botón #,
la última letra se elimina del mensaje.
Dadas algunas pulsaciones de teclas:
 muestra el mensaje resultante.
Input:
abc#de##f#ghi#jklmn#op#
Output: abghjkl


*/


string backspace(string s){
    string output = "";
    deque<char>dq;
    for(auto cad:s)
    {
        if(cad=='#')
           dq.pop_back();
        else
           dq.push_back(cad);
    }
   
    while(!dq.empty()){
		output+= dq.front();
		dq.pop_front();
	}
    return output;
}

int main(){

    string s = "abc#de##f#ghi#jklmn#op#";
    cout << backspace(s);
    return 0;
}