#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int n;
int pedacos[MAX];

int solve(){
    int resp=0, larger=0;
    for(int i=0; i<n; i++){
        larger = max(0, larger+pedacos[i]);
        resp = max(resp, larger);
    }
    int newResp=0, overallSum=0;
    larger = 0;
    for(int i=0; i<n; i++){
        overallSum += pedacos[i];
        pedacos[i] *= -1;
    }
    for(int i=0; i<n; i++){
        larger = max(0, larger+pedacos[i]);
        newResp = max(newResp, larger);
    }
    
    return max(resp, overallSum+newResp);
}

int main(){
    cin >> n;
    int sum = 0;
    for(int i=0; i<n; i++)
        cin >> pedacos[i];
    
    cout << solve() << endl;
}