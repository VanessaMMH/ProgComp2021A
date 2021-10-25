#include <bits/stdc++.h>
using namespace std;

/*
link: https://leetcode.com/problems/score-of-parentheses/
*/


int scoreOfParentheses(string s){
    int last , result=0;
    stack<int> pila ;
    for( auto c : s)
    {
        if (c == '(')
            pila.push(-1);
        else if(c==')')
        {
            if(pila.top() == -1)
            {
                pila.pop();
                pila.push(1);
            }
            else{
                int last= 0;
                while(pila.top() != -1){
                    last+= pila.top();
                    pila.pop();
                }
            pila.pop(); 
            pila.push(last* 2);
            }
        }   
    } 
    while(pila.size()>0){
        result += pila.top();
        pila.pop();
    }
    return result;
}


int main(int argc, char const *argv[])
{
    string s ="(()(()))";
    cout << scoreOfParentheses(s);
}
