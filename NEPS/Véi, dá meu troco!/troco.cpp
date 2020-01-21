#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int n, m;
int moedas[MAX];
int dp[MAX];

bool solve(int m){
    if(m<0)
        return false;
    int *pdp = &dp[m];
    if(*pdp!=-1)
        return *pdp;
    if(m==0)
        return dp[m] = 1;
    for(int i=0; i<n; i++)
        if(solve(m-moedas[i]))
            return dp[m] = 1;
    return dp[m] = 0;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> moedas[i];
    cout << (solve(m) ? "S" : "N") << endl;
}