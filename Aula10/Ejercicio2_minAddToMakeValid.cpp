#include <bits/stdc++.h>
using namespace std;

/*
link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

*/

int minAddToMakeValid(string s) {
    stack<char> pila;
    bool flag;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i]==')' && pila.size()>0 && pila.top()=='(')
            pila.pop();
        else
            pila.push(s[i]);                  
    }   
    return pila.size();   
}

int main(int argc, char const *argv[])
{
    // string s ="())";
    string s ="((())";
    cout << minAddToMakeValid( s);
    return 0;
}
