#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers that is already sorted in ascending order, find two
numbers such that they add up to a specific target number.

*/
void print(vector<int> &v){
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}



vector <int> two_pointers(vector<int>& v, int target) {
        int j=v.size()-1;
        if (v.size()>1)
        {
              for (int i = 0; i < v.size(); i++)   
                { 
                    if (i==j)
                        break;
                    if (v[i]+v[j]==target)
                    {
                        cout << "[" <<" "<< i+1 << " " << j+1<< "]";
                        return {i+1,j+1};
                                               
                                
                    }
                    else if (v[i]+v[j]>target)              
                        i--;
                    else
                        j++;
                    j--;
                    
                }
        }    
        // cout << "IMPOSSIBLE";
        return {-1};
       
       
    }

int main(int argc, char const *argv[])
{
    
    vector <int> v1 ={1,2,7,9,11,15};
    vector <int> v2={-1, 1, 2, 3, 5};
    two_pointers(v1,11);
    two_pointers(v2,5);

  

    return 0;
}
