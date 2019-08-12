#include <bits/stdc++.h>
using namespace std;

int n;
bool isPrime[1100];

int main(){
    cin >> n;
    for(int i=2; i<=n; i++)
        isPrime[i]=true;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i])
            for(int j=i*2; j<=n; j+=i)
                isPrime[j] = false;
    }
    for(int i=2; i<=n; (i==2 ? i++ : i+=2)){
        if(isPrime[i])
            cout << i << " ";
    }
}