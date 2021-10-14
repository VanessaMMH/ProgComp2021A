#include <iostream>
#include <algorithm>    // std::max
using namespace std;

class Nodo
{

public:
    int value;
    Nodo* left;
    Nodo* right;
    Nodo(int value){
        this->value=value;
        this->left=nullptr;
        this->right=nullptr;
    }
    
};

class tree
{

public:
    Nodo* root;
    tree(){
        root=nullptr;
    }
    void add(int value){
       
        Nodo* nuevo= new Nodo(value);
        //  cout << &root << " "<< root <<" " << &nuevo << endl;
        if (root==nullptr){
            root=nuevo;
            // cout << root << " " << &nuevo << endl;

        }
        else{
            Nodo* aux=root;
            Nodo* temp= nullptr; 
            // cout << "ux " << aux <<  " " << &root << endl;

           do
           {
            //    cout << aux->value  <<" " << nuevo->value<< endl;
                temp=aux; 
               if (nuevo->value<aux->value)
               {
                  
                  aux=aux->left;
               }
               else{
                   aux=aux->right;
               }               
           }while (aux!=nullptr  );
           if (temp->value<value )
           {
               temp->right=nuevo;
           }
           else{
               temp->left=nuevo;
           }           
        }
    }
    int  height(Nodo* n){
     
        
        if (n== nullptr )
        {
            return 0;
        }
        return max(height(n->left), height(n->right)) +1;
    }

  bool balanceado(){
        if(height(root->left)== height(root->right))
            return true;
        else
            return false;
    }
};





int main(int argc, char const *argv[])
{
    tree t;
    t.add(5);
    t.add(3);
    
    t.add(7);
    t.add(1);
    t.add(2);
    t.add(4);
    cout << "h " << t.height(t.root) << endl;
    cout << t.balanceado()<<endl;
    return 0;
}
