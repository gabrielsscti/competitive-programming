#include <bits/stdc++.h>

using namespace std;

set<int> tacos;
int c, r = 0;

int main(){
    cin >> c;
    for(int i=0; i<c; i++){
        int taco;
        cin >> taco;
        if(tacos.find(taco)!=tacos.end())
            tacos.erase(taco);
        else{
            tacos.insert(taco);
            r+=2;
        }
    }
    cout << r << endl;
    return 0;
}