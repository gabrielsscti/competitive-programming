#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int gene1[MAX], gene2[MAX];
int n, m;
int dp[MAX][MAX];

int getCommonAncestor(int a, int b){
    if(a==-1 || b==-1)
        return 0;
    int *pdp = &dp[a][b];
    if(*pdp!=-1)
        return *pdp;
    if(gene1[a]==gene2[b])
        return *pdp = 1+getCommonAncestor(a-1, b-1);
    return *pdp = max(getCommonAncestor(a-1, b), getCommonAncestor(a, b-1));
}

int main(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
        cin >> gene1[i];
    for(int i=0; i<m; i++)
        cin >> gene2[i];
    int r = getCommonAncestor(n-1, m-1);
    cout << n-r << " " << m-r << endl;
}