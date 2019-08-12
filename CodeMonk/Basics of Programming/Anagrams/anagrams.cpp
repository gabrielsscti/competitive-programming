#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        for(int i=0; i<a.length(); i++){
            for(int j=0; j<b.length(); j++){
                
                if(a[i]==b[j]){
                    a.erase(i, 1);
                    i--;
                    b.erase(j, 1);
                    break;
                }
            }
        }
        cout << abs((a.length()+b.length())) << endl;
    }
}