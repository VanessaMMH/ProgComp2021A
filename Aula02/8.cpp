#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::string;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

int contar_1(string s1){
    int count=0;
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i]=='1')
        {
            count++;
        }        
    }
    return count;

}

int numero_bits(string s1 , string s2){
    return abs(contar_1( s1)-contar_1( s2));
}

int main() {
    int n1 = 31;
    int n2 = 14;

    cout << "decimal: " << n1 << endl;
    cout << "binary : " << toBinary(n1) << endl;
    cout << "decimal: " << n2 << endl;
    cout << "binary : " << toBinary(n2) << endl;
    cout << numero_bits(toBinary(n1),toBinary(n2)) << endl;
    return 0;
}