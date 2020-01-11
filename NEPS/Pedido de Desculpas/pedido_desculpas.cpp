//https://neps.academy/lesson/182
#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int numChar, numDesc;
}Frase;

int dp[51][1010];
Frase frases[51];
int c, f;

int solve(int idFrase, int charRestantes){
    if(idFrase == f || charRestantes==0)
        return 0;
    int *pdp = &dp[idFrase][charRestantes];
    if(*pdp!=-1)
        return *pdp;
    if(charRestantes-frases[idFrase].numChar<0)
        return *pdp = solve(idFrase+1, charRestantes);
    return *pdp = max(solve(idFrase+1, charRestantes), frases[idFrase].numDesc+solve(idFrase+1, charRestantes-frases[idFrase].numChar));
}

int main(){
    cin >> c >> f;
    int cont =0;
    while(c!=0 && f!=0){
        for(int i=0; i<f; i++)
            cin >> frases[i].numChar >> frases[i].numDesc;
        memset(dp, -1, sizeof(dp));
        printf("Teste %d\n", ++cont);
        cout << solve(0, c) << endl;
        cin >> c >> f;
    }
}

