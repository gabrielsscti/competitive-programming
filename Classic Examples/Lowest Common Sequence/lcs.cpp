#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int v1[MAX], v2[MAX];
int dp[MAX][MAX];

int solve(int a, int b){
    int *pdp = &dp[a][b];
    if(*pdp!=-1)
        return *pdp;
    if(a==0 || b==0)
        return *pdp = 0;
    if(v1[a]==v2[b])
        return *pdp = 1+solve(a-1, b-1);
    return *pdp = max(solve(a-1, b), solve(a, b-1));
}

int main(){
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=a; i++)
        cin >> v1[i];
    for(int i=1; i<=b; i++)
        cin >> v2[i];
    cout << solve(a, b) << endl;

}