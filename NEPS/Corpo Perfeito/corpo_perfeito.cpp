#include <bits/stdc++.h>
#define MAX 2010
#define INF 0x3f3f3f3f
using namespace std;

typedef struct{
    int peso, valor;
}Pedaco;

Pedaco pedacos[MAX];
int p, n;
int dp[MAX][MAX];

int solve(int idPedaco, int pesoRestante){
    if(idPedaco==n)
        return 0;
    if(pesoRestante<0)
        return -INF;
    int *pdp = &dp[idPedaco][pesoRestante];
    if(*pdp!=-1)
        return *pdp;
    if(pesoRestante==0)
        return *pdp = 0;
    if(pesoRestante-pedacos[idPedaco].peso<0)
        return *pdp = solve(idPedaco+1, pesoRestante);
    return *pdp = max(solve(idPedaco+1, pesoRestante), pedacos[idPedaco].valor+solve(idPedaco+1, pesoRestante-pedacos[idPedaco].peso));
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> p >> n;
    for(int i=0; i<n; i++)
        cin >> pedacos[i].peso >> pedacos[i].valor;
    cout << solve(0, p) << endl;
}