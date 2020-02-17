#include <bits/stdc++.h>

using namespace std;

set<int> frequencia;
int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        frequencia.insert(temp);
    
    }
    cout << frequencia.size() << endl;
}