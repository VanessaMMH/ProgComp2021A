#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    vector <int> sumas;
    int n, acum=0;
    cout << "n?:";
    cin >> n;
    int vec[n];
    sumas.push_back(acum); 
    for (size_t i = 0; i < n; i++)
    {
        cin >> vec[i];
        acum+=vec[i];
        sumas.push_back(acum);
    }
    for (size_t i = 0; i < sumas.size(); i++)
    {
        cout << sumas[i] << " ";
    }
    
    
    
    return 0;
}
