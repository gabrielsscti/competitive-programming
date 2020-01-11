#include <bits/stdc++.h>
#define NUMCOINS 6
#define MAXSAQUE 5000
#define MAXVAL 500

using namespace std;

typedef struct{
    int value;
    int quant;
}Coin;
Coin coins[6];
int values[] = {2, 5, 10, 20, 50, 100};
int dp[MAXSAQUE+10][NUMCOINS+2][MAXVAL+10];
int s;

int solve(int saque, int actCoin, int rCoins){
    if(saque<0 || actCoin==NUMCOINS)
        return 0;
    int *dpPtr = &dp[saque][actCoin][rCoins];
    if(*dpPtr!=-1)
        return *dpPtr;
    if(saque==0)
        return *dpPtr = 1;
    if(rCoins == 0)
        return *dpPtr = solve(saque, actCoin+1, coins[actCoin+1].quant);
    return *dpPtr = solve(saque-coins[actCoin].value, actCoin, rCoins-1) + solve(saque, actCoin+1, coins[actCoin+1].quant);
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> s;
    for(int i=0; i<NUMCOINS; i++){
        cin >> coins[i].quant;
        coins[i].value = values[i];
    }
    cout << solve(s, 0, coins[0].quant) << endl;
    
}