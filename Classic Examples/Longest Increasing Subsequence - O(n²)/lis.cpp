#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int v[MAX];
int dp[MAX];

int solve(int a){
    int *pdp = &dp[a];
    if(*pdp!=-1)
        return *pdp;
    int r = 1;
    for(int i=0; i<a; i++)
        if(v[i]<v[a])
            r = max(r, 1+solve(i));
    return *pdp = r;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int r = 0;
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
        v[i] = rand()%1000;
    cout << "Longest Increasing Subsequence for \n";
    for(int i=0; i<MAX; i++)
        cout << v[i] << " ";
    for(int i=0; i<MAX; i++)
        r = max(r, solve(i));
    cout << endl <<"is: " << r;
    
}