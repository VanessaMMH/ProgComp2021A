#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int find_pivot(int*b,int n){
	int i=0;
	for(;i<n+1;i++){
		if(b[i-1]==b[n]-b[i])break;	
	}
	return i-1;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int a[]={1,-1,4};
    int n=sizeof(a)/sizeof(a[0]);
    int* b = new int[n+1];
    b[0]=0;
    for(int i=0;i<n;i++){
        b[i+1]=b[i]+a[i];
    }
    int k=find_pivot(b,n);
    if(k<n)
        cout << k<< "\n";
    else
        cout << "-1"<< "\n";
    return 0;
}
