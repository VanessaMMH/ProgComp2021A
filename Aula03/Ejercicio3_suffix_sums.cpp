#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    vector <int> sumas;
    int n,j=0, acum=0;
    cout << "n?:";
    cin >> n;
    int vec[n];
     
    for (size_t i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    
    for (int i = n-1; i >= 0; --i)
    {           
        acum+=vec[i];
        sumas.push_back(acum);
        cout << sumas[j] << " ";//Va mostrando la suma sufija
        j++;       
    }
    return 0;
}
