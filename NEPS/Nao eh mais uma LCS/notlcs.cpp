#include <bits/stdc++.h>
#define MAX 10001
//RESOLVER COM FENWICK TREE

using namespace std;

int n, m;
int s[MAX], r[MAX];
int dp[MAX][MAX];

int solve(int a, int b){
    if(a==-1 || b==-1)
        return 0;
    int *pdp = &dp[a][b];
    if(*pdp!=-1)
        return *pdp;
    if(s[a]==r[b])
        return 1+solve(a-1, b-1);
    return max(solve(a-1, b), solve(a, b-1));
};

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=0; i<m; i++)
        cin >> r[i];
    cout << solve(n-1, m-1);
}