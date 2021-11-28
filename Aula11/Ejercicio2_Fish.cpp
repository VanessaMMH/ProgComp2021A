#include <bits/stdc++.h>
using namespace std;

/*
link: https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/

*/

int Fish(vector<int> &A, vector<int> &B) {
    stack<pair<int,int>> peces_vivos; 
    peces_vivos.push(make_pair(B[0], A[0]));
    for(int i=1;i<A.size();i++){
        if(B[i]==0 && peces_vivos.top().first==1){ 
            if(A[i]>peces_vivos.top().second){
                while(true){
                    if(peces_vivos.empty() || B[i]==peces_vivos.top().first){
                        peces_vivos.push(make_pair(B[i], A[i]));
                        break;
                    }
                    else if(A[i]<peces_vivos.top().second) 
                        break;
                    peces_vivos.pop();
                }
            }
        }
        else 
            peces_vivos.push(make_pair(B[i], A[i]));
    }
    return peces_vivos.size();
}

int main(){
    vector<int> A = {4,3,2,1,5};
    vector<int> B = {0,1,0,0,0};
    cout << Fish(A,B);
}