#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int a, b;
set<int> cartasA, cartasB;

int main(){
    cin >> a >> b;
    for(int i=0; i<a; i++){
        int temp;
        cin >> temp;
        cartasA.insert(temp);

    }
    for(int i=0; i<b; i++){
        int temp;
        cin >> temp;
        cartasB.insert(temp);
    }
    int equals = 0;
    for(auto it=cartasA.begin(); it!=cartasA.end(); it++){
        if(cartasB.find(*it)!=cartasB.end())
            equals++;
    }
    cout << (cartasA.size()>cartasB.size() ? cartasB.size()-equals : cartasA.size()-equals) << endl;
}