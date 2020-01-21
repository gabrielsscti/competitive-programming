#include <bits/stdc++.h>
#define MAX 1010
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int moedas[MAX], dp[MAX];

int solve(int m){
    if(m<0)
        return INF;
    int *pdp = &dp[m];
    if(*pdp!=-1)
        return *pdp;
    if(m==0)
        return *pdp = 0;
    int r = INF;
    for(int i=0; i<n; i++)
        r = min(r, 1+solve(m-moedas[i]));

    return *pdp = r;
    
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> moedas[i];
    cout << (solve(m)<10 ? "S" : "N") << endl;
}