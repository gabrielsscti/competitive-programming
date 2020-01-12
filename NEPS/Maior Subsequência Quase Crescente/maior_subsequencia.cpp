#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int n;
int s[MAX];
int dp[MAX];

int solve(int a){
    int *pdp = &dp[a];
    if(*pdp!=-1)
        return *pdp;
    if(a==0)
        return *pdp = 1;
    int r = 1;
    for(int i=0; i<a; i++)
        if(s[i]<=s[a])
            r = max(r, 1+solve(i));
    return *pdp = r;
}

int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int r =0;
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=0; i<n; i++)
        r = max(r, solve(i));
    cout << r << endl;
}