#include <bits/stdc++.h>
using namespace std;

/*
link: https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/

*/

bool brackets(string &s){
    stack<char>pila;
    for(auto cad:s){
        if (cad == '{' || cad == '(' || cad == '[')
            pila.push(cad);
        else if (cad == '}' || cad == ')' || cad == ']') {
            char aux=pila.top();
            pila.pop();
            string temp ;
            temp.push_back(aux);
            temp.push_back(cad);
            if (temp != "{}" && temp != "()" && temp != "[]")
                return 0;
        }
        else 
            return 0;
    }
    if (pila.size() > 0)
        return 0;

    return 1;

}


int main(int argc, char const *argv[])
{
    string s="{[()()]}";
    cout << brackets(s);

    return 0;
}
