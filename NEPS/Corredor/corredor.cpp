#include <bits/stdc++.h>
#define MAX 50010
using namespace std;

int n;
int values[MAX];

int solve(){
    int r=0, maior=0;
    for(int i=0; i<n; i++){
        maior = max(0, maior+values[i]);
        r = max(r, maior);
    }
    return r;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> values[i];
    cout << solve() << endl;
}