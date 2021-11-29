#include <bits/stdc++.h>
using namespace std;


/*

link: https://leetcode.com/problems/asteroid-collision/

*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> vec;
    for(int i=0; i<asteroids.size(); i++){
        int aux = asteroids[i];
        if(vec.empty()){
            vec.push_back(aux);
            continue;
        }
        while(true){
            if(vec.size() != 0 && aux < 0 && vec.back() > 0){
                if(vec.back() + aux == 0){
                    vec.pop_back();
                    break;
                }
                else if (vec.back() + aux > 0){
                    break;
                }else if(vec.back() + aux < 0){
                    vec.pop_back();
                    
                }
            }else{
                vec.push_back(aux);
                break;
            }
        }
    }
    return vec;
}

int main(int argc, char const *argv[]){
    
    vector<int> asteroids = {5,10,-5};
    vector<int> vec = asteroidCollision(asteroids);
    for (auto  i :vec)
    {
        cout << i << " ";
    }
    
    return 0;
}