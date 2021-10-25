#include <bits/stdc++.h>
using namespace std;

/*
link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

*/

int minAddToMakeValid(string s) {
    stack<int> pila;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i]=='(' && s[i+1]==')' )
            i++;
        else
            pila.push(s[i]);       
    }
    return pila.size();   
}

int main(int argc, char const *argv[])
{
    // string s ="())";
    string s ="()))((";
    cout << minAddToMakeValid( s);
    return 0;
}
