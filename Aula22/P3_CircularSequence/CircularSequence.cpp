#include <bits/stdc++.h>
using namespace std;

/*
link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4459
*/

int T;
string s, first, second;

int main(int argc, char** argv) { 
    cin >> T;
	while(T--){
        cin >> s;
		
        int len = s.length();
		vector<string> vec;
		vec.push_back(s);

		for(int i=1; i < len; i++){
			first = s.substr(i);
			second = s.substr(0,i);
			vec.push_back(first+second);
		}
		sort(vec.begin(),vec.end());
		
        cout << vec[0] << endl;
	}
	return 0;
}