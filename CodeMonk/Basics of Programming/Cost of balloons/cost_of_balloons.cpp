#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int greenCost, purpleCost, n, p1=0, p2=0;
        cin >> greenCost >> purpleCost;
        cin >> n;
        for(int i=0; i<n; i++){
            int first, second;
            cin >> first >> second;
            p1 = first==1 ? p1+1 : p1;
            p2 = second==1 ? p2+1 : p2;

        }
        int cost = max(p1, p2)*min(greenCost, purpleCost) + min(p1, p2)*max(greenCost, purpleCost);
        cout << cost << endl;
    }
}