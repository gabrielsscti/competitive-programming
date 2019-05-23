#include <bits/stdc++.h>
#define MAX 1010
#define INF 0x3f3f3f3f
using namespace std;

int n;
struct Caixa{
    int p, r;
};
Caixa caixas[MAX];
int dpMemo[MAX][MAX];

int dp(int ind, int actPeso){
    if(ind==n || actPeso<0)
        return 0;
    
    int& actpd = dpMemo[ind][actPeso];
    if(actpd!=-1) return actpd; 

    return actpd = max(1+dp(ind+1, min(actPeso-caixas[ind+1].p, caixas[ind+1].r-caixas[ind+1].p)),
                       dp(ind+1, caixas[ind+1].r-caixas[ind+1].p));
    
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> caixas[i].p >> caixas[i].r;
    
    memset(dpMemo, -1, sizeof(dpMemo));
    cout << dp(0, caixas[0].r-caixas[0].p) << endl;
    for(int i=0; i<MAX; i++)
        for(int i2=0; i2<MAX; i2++)
            if(dpMemo[i][i2]!=-1){
                cout << "Caixa: " << i+1 << " Resistencia Atual: " << i2 << "\t";
                cout << dpMemo[i][i2] << " ";
                cout << endl;
            }
    return 0;
}