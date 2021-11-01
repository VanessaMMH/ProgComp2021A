#include<bits/stdc++.h>
using namespace std;

int  operador(char c){
    switch(c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
    }

}
int main()
{
 
    string s;
    stack <char> mystack;
    vector <char> output;
    int tc;
 
    cin>>tc;
    while(tc--){
        cin>>s;
    
        for(int i=0;i<s.length();i++){
    
                if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
                    while( !mystack.empty() && operador(mystack.top()) >= operador(s[i]) ){
                        output.push_back(mystack.top());
                        mystack.pop();
                    }
                    mystack.push(s[i]);
                }
                else if(s[i] == '('){
                    mystack.push(s[i]);
                }
                else if( s[i]==')' ){
                    while( mystack.top() !='(' ){
                        output.push_back(mystack.top());
                        mystack.pop();
                    }
                    mystack.pop();
                }
                else {
                    output.push_back(s[i]);
                }
    
        }
    
        while( !mystack.empty() ){
            output.push_back(mystack.top());
            mystack.pop();
        }

        for(int i=0;i<output.size();i++){
            cout<<output[i];
        }
        cout<<endl;
        while(!output.empty()){
            output.pop_back();
        }
 
    }
 
    return 0;
}

