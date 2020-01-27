#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

int dp[MAX][2];
int n, c;
int p[MAX];

int solve(int pos, int isSold){
    if(pos==n)
        return 0;
    int *pdp = &dp[pos][isSold];
    if(*pdp!=-1)
        return *pdp;
    if(!isSold)
        return *pdp = max(-(p[pos]+c-solve(pos+1, 1)), solve(pos+1, 0));
    return *pdp = max(p[pos]+solve(pos+1, 0), solve(pos+1, 1));

}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> c;
    for(int i=0; i<n; i++)
        cin >> p[i];
    cout << solve(0, 0) << endl;
}