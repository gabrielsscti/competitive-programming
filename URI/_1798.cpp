#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, t;
int dpMemo[1010][2010];
struct Cano{
    int comprimento;
    int valorVenda;
};
Cano cano[1010];

int solve(int numCano, int tamanhoRestante){
    if(numCano==n || tamanhoRestante==0)
        return 0;
    if(tamanhoRestante<0)
        return -INF;
    int& actDp = dpMemo[numCano][tamanhoRestante];
    if(actDp!=-1)
        return actDp;
    Cano& actCano = cano[numCano];
    return actDp = max(actCano.valorVenda + solve(numCano, tamanhoRestante-actCano.comprimento),
                       solve(numCano+1, tamanhoRestante));
                       


}

int main(){
    cin >> n >> t;
    for(int i=0; i<n; i++)
        cin >> cano[i].comprimento >> cano[i].valorVenda;
    memset(dpMemo, -1, sizeof(dpMemo));
    cout << solve(0, t) << endl;
}