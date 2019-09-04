#include <bits/stdc++.h>
#define MAX 110

using namespace std;

int memo[MAX][MAX];
int caixa[MAX][MAX];
int n;

int dp(int x, int y){
    if(memo[x][y]!=-1)
        return memo[x][y];
    if(x==0)
        return memo[x][y] = caixa[x][y];
    int sum = 0;
    for(int i=0; i<=x; i++)
        sum += caixa[x][y+i];
    return memo[x][y] = sum + min(dp(x-1, y), dp(x-1, y+1));
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> caixa[i][j];
    memset(memo, -1, sizeof(memo));
    
    cout << dp(n-1, 0) << endl;
    
}