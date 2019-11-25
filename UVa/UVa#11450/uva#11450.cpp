#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int k[21];
int price[21][21];
int dp[210][21];

int solve(int money, int g){
    if(money<0) return -99999999;
    if(g==c) return m-money;
    if(dp[money][g]!=-1)
        return dp[money][g];
    int ans = -1;
    for(int i=0; i<k[g]; i++)
        ans = max(ans, solve(money-price[g][i], g+1));
    return dp[money][g] = ans;
}

int main(){
    scanf("%d", &n);
    
    while(n--){
        scanf("%d%d", &m, &c);
        for(int i=0; i<c; i++){
            scanf("%d", &k[i]);
            for(int j=0; j<k[i]; j++)
                scanf("%d", &price[i][j]);
            
        }
    
        memset(dp, -1, sizeof(dp));
        int score = solve(m, 0);
        if(score<0)
            printf("no solution\n");
        else
            printf("%d\n", score);
        printf("\n");
        for(int i=0; i<101; i++){
            for(int j=0; j<10; j++){
                printf("%d ", dp[i][j]);
                
            }
            printf(" com %dR$", i);
            printf("\n");
        }
    }
}