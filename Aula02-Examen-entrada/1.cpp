#include <iostream>
#include "string"
#include <map>
using namespace std;

void anagrama(string word1, string word2){
    bool flag=true;
    if (word1.size()==word2.size())
    {       
        int tam= word1.size();
        for (size_t i = 0; i < tam; i++)
        {
            char ch1=word1[i];
            for (size_t j = 0; j < tam; j++)
            {
               cout<< ch1  <<" - "<< word2[j] <<endl ;
               //roma - amer
                if (ch1!= word2[j]&& j==tam-1)
                {  
                    flag=false;
                    break;                    
                }
                if(ch1== word2[j]){
                    break;
                }                                                
            }    
             if (!flag)
            {
                break;
            }                   
        }
        if (flag)
        {
            cout << "anagrama" << endl;
        }
        else
            cout << " no anagrama" << endl;       
    }   
    else
    {
        cout << "No es anagrama "<<endl;
    }        
}

int main(int argc, char const *argv[])
{
    anagrama("roma","amor");
    return 0;
}
