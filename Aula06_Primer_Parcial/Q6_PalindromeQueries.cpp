#include <bits/stdc++.h>
using namespace std;
/*
https://cses.fi/problemset/task/2420

*/
bool palindromo(string s,unsigned int a, unsigned int b){
       
    unsigned int l = a;
    unsigned int h = b;

    while(h >= l){
        if(s[l++] != s[h--]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long n,size_string;
    unsigned int opt , value1, value2;
    char rval2;
    cin  >> size_string >> n;
    char ss[size_string];
    cin >> ss;
    for (long i = 0; i < n; i++)
    {
        cin >> opt;
        
        switch (opt)
        {
            case 1:
            {
                cin >> value1 >> rval2;
                ss[value1-1]=rval2;
                break;
            }
            case 2:
            {
                cin >> value1 >> value2;
                if (palindromo(ss, value1- 1, value2-1))
                    cout << "YES";
                else
                    cout << "NO";
                
                cout << "\n";
                break;
            }
            
            default:
                break;
        } 
    }
    
    return 0;
}