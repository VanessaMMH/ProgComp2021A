#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


long fibonacci_recursive(int n){
    if(n == 0 || n == 1)
        return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

long fibonacci(int n, vector<long>& memo){
    if(memo[n]) return memo[n];
    long result{};
    if(n <= 1)
        result = n;
    else
        result = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    memo[n] = result;
    return result;
}

long fibonacci_memoization(int n){
    vector<long> memo(n+1);
    return fibonacci(n, memo);
}

long fibonacci_bottomup(int n){
    if(n <= 1)
        return n;
    vector<long> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main(int argc, char const *argv[])
{
    cout << fibonacci_recursive(4) << endl;
    cout << fibonacci_memoization(4) << endl;
    cout << fibonacci_bottomup(4) << endl;
    return 0;
}