#include <bits/stdc++.h>
using namespace std;

/*
Find three numbers in a sorted array that sum to a target

*/

vector<int> sums_three(vector<int>& v, int target,int n ) {
        if (n>2)
        {
            for (int k  = 0; k < n; k++)
            {
                int target_temp=target-v[k];
                int j=n-1;
                for (int i = k+1; i < n; i++)   
                { 
                    if (v[i]+v[j]==target_temp)
                    {
                        cout << "[" <<k+1<<" "<< i+1 << " " << j+1<< "]";                        
                        return{k+1,i+1,j+1};           
                    }
                    if (v[i]>=v[j])              
                        i--;
                    else
                        j++;
                    j--;
                    if (i==j)
                        break;
                }
            } 
        }
        return {-1,-1,-1};          
    }

int main(int argc, char const *argv[])
{
    
    vector <int> v1 ={1,2,4,5,12};
    int n = v1.size();
    vector <int> v2={1 ,2, 1, 2, 2, 1, 1};  

    sums_three(v1,19,n);
    sums_three(v2,5,7);
  
  

    return 0;
}
