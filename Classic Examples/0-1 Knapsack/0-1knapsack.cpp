#include <bits/stdc++.h>
//Enunciado problema: https://www.spoj.com/problems/KNAPSACK/
using namespace std;

typedef struct{
    int p, v;

}Item;

int s, n;
int dp[2010][2010];
Item itens[2010];

int solve(int id, int peso){
    if(peso==0 || id==n)
        return 0;
    if(dp[id][peso]!=-1)
        return dp[id][peso];
    
    if(itens[id].p>peso)
        return dp[id][peso] = solve(id+1, peso);
    return dp[id][peso] = max(solve(id+1, peso), itens[id].v+solve(id+1, peso-itens[id].p));
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> s >> n;
    for(int i=0; i<n; i++)
        cin >> itens[i].p >> itens[i].v;
    cout << solve(0, s);
}