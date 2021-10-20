
#include <bits/stdc++.h>
using namespace std;
stack<int> pila;
void sumar(){
	int a = pila.top();
	pila.pop();
	int b = pila.top();
	pila.pop();
	int suma = a+b;
    pila.push(suma);
    
}
void restar(){
	int a = pila.top();
	pila.pop();
	int b = pila.top();
	pila.pop();
	int resta = b-a;
    pila.push(resta);
}

void multiplicar(){
	int a = pila.top();
	pila.pop();
	int b = pila.top();
	pila.pop();
	int multiplica = b*a;
    pila.push(multiplica);
}
void dividir(){
	int a = pila.top();
	pila.pop();
	int b = pila.top();
    pila.pop();
    if (a==0)
    {
        pila.push(0);
    }
	int divide = b/a;
    pila.push(divide);
}

int read(vector <string>& tokens){
    string simbolo;
    char s;
    int value;
    for (size_t i = 0; i < tokens.size(); i++)
    {
        if(tokens[i]=="+") sumar();
        else if(tokens[i]=="-")restar(); 
        else if(tokens[i]=="*")multiplicar();
        else if(tokens[i]=="/") dividir();
        else{
            value=stoi(tokens[i]);
            pila.push(value);
        }
    }
    return pila.top();     
 }

int main(){	
    
	vector <string> tokens={"4","13","5","/","+"};

	cout << read(tokens);     	
	
}


