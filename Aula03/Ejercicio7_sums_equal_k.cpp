#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& v, int k) {

    int c=0;
    vector <int> suma;
    for (size_t i = 0; i < v.size(); i++)   
    {
        int acum=0;
       for (size_t j = i   ; j < v.size(); j++)
       {
            acum+=v[j];
            if (acum==k)
            {
                //cout << acum << " ";
                c++;
            }
       }       
    }
    return c;
}

int main(int argc, char const *argv[])
{
    
    vector <int> v1 ={1,1,1};
    vector <int> v2 ={1,2,3};
    cout << subarraySum(v1,2);
    cout << subarraySum(v2,3);
    return 0;
}
