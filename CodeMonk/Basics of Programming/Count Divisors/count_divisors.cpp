#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, r, k;
    cin >> l >> r >> k;
    if(l==1)
        cout << r/k << endl;
    else{
        int ans;
        if(l%k==0){
            ans = r/k;
            ans -= (l/k)-1;

        }else{
            ans = r/k;
            ans -= l/k;
        }
        cout << ans;
    }
}