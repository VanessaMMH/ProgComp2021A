#include <bits/stdc++.h>
using namespace std;
//Funcion para determinar cuantos numeros son divisibles por k
void intest(long &n, long &k , long &t){
	int cont=0;
	for (int i=0; i<n; i++)
	{
		cin >> t;
		if (t % k == 0)//Verifica si es divisible por k
			cont++;
	}
	cout << cont << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long n, k, t;
	cin >> n >> k;
	intest(n, k , t);
	
	return 0;
}
