#include <bits/stdc++.h>
#define MAX 1010
#define INF 0x3f3f3f3f
#define debug(x) cout << #x << ": " << x << endl;
using namespace std;

typedef struct _caixa_{
    int peso, resistencia;
}Caixa;

bool compara(Caixa c1, Caixa c2){
    return c1.resistencia>c2.resistencia;
}

int n;
int dp[1010][1010];
Caixa caixas[1010];

int solve(int id, int h){
    if(dp[id][h]!=-1)
        return dp[id][h];
    if(h==0)
        return dp[id][h] = INF;
    if(id==0){
        if(h==1) return  dp[id][h] = caixas[id].resistencia-caixas[id].peso;
        return -INF;
    }
    int getThis = min(caixas[id].resistencia-caixas[id].peso, solve(id-1, h-1)-caixas[id].peso);
    int passThis = solve(id-1, h);
    return dp[id][h] = max(getThis, passThis);
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> caixas[i].peso >> caixas[i].resistencia;
    
    sort(caixas, caixas+n, compara);
    for(int i=0;i<=n; i++)
        solve(n-1, i);

    int r = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=1; j<=n; j++){
            if(dp[i][j]>=0)
                temp++;
        }
        r = max(temp, r);
    }
    cout << r << endl;
    
}