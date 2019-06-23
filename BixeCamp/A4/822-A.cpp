#include <bits/stdc++.h>
using namespace std;

int a, b;

long long int getFact(int n){
    long long int r = 1;
    for(int i=2; i<=n; i++)
        r *= i;
    return r;
}



int main(){
    cin >> a >> b;
    cout << getFact(min(a, b));
}