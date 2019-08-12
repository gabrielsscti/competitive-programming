#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int ans = 1;
    for(int i=0; i<n; i++){
        long long int temp;
        cin >> temp;
        ans = (ans*temp) % ((int)pow(10, 9)+8);
    }
    cout << ans;
}