#include<bits/stdc++.h>

using namespace std;

void evenAndOdd(vector <int> &v){
    sort(v.begin(),v.end());
    for (auto i = 0; i < v.size(); i++)
    {
        if (v[i]%2==0)
        {
            cout << v[i] << "\n";
        }      
    }
     for (int i = v.size()-1; i >=0 ; i--)
    {
        if (v[i]%2!=0)
        {
            cout << v[i] << "\n";
        }      
    }
    

}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vector<int> v;
    int value,n;
    cin>> n;
    while (n--)
    {
        cin >> value;
        v.push_back(value);
    }
    evenAndOdd(v);

    return 0;
}
