#include <bits/stdc++.h>
using namespace std;

/*
Dada una matriz, hay una ventana deslizante de tamaño k 
que se mueve desde el extremo izquierdo de la matriz hacia la derecha.
Solo puede ver los k números en la ventana.
 Cada vez que la ventana deslizante se mueve hacia la derecha una posición.
*/

void print(vector<int> &v){
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

vector<int> Sliding_Window_Maximum( vector<int> &v, int k) {
      
    vector<int> vec;
    deque<int> dq;
        
    for(auto i=0; i<v.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        
        while(!dq.empty() && v[i] >= v[dq.back()])
            dq.pop_back();
            
        dq.push_back(i);
        
        if(i >= k-1){
            vec.push_back(v[dq.front()]);
            // cout << v[dq.front()] << " ";
        }
       
    }
    
    return vec;
}
int main(){

    vector <int> v={1, 3, -1, -3, 5, 3, 6, 7};
    vector <int> result =Sliding_Window_Maximum(v,3);
    for (auto e : result)
    {
        cout << e << " "; 
    }
    

    return 0;
}