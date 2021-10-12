#include <iostream>
#include <vector>
using namespace std;

void printVector(vector <int> vec){
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec.at(i) << " ";
    }
     cout<<endl;
}
bool estaValor(vector <int> vec, int valor){
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (valor== vec.at(i))
        {
            return true;
        }       
    }
    return false;
}
void run(vector <int > &vec_main,int valor, vector<int> &vec){
    int cont=1;
    for (size_t i = 0; i < vec_main.size(); i++)
    {        
        for (size_t j =i+cont; j < vec_main.size(); j++)
        {           
            if (vec_main.at(i)==vec_main.at(j))
            {
                if (!estaValor(vec,vec_main.at(i)))
                {
                    vec.push_back(vec_main.at(i));
                    i++;
                    cont++;
                }                
            }            
        }        
    }   
}

int main(int argc, char const *argv[])
{
    vector <int >vec_main;
    vector <int > vec;
    int valor;
    cout << "Para finalizar ingrese -1 " <<endl;
    do{
        cin>> valor;
        vec_main.push_back(valor);
        run(vec_main,valor, vec);
    }while(valor!=-1);
    printVector(vec);    
    return 0;
}
