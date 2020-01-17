#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int t;

int main(){
    cin >> t;
    while(t--){
        lli a, b;
        cin >> a >> b;
        string temp = to_string(b+1);
        cout << (a*(to_string(b+1).length()-1)) << endl;

    }
}