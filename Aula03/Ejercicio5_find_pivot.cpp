
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector <int>nums){
	int sum=0, psum=0;
	for(int x:nums) sum+=x;
	for(int i = 0 ; i < nums.size();i++)	{
		if(psum==sum-psum-nums[i]) return i;
		psum += nums[i];
	}
	return -1;


}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector <int> v ={1,-1,4};
	cout << pivotIndex(v);
	return 0;
}
