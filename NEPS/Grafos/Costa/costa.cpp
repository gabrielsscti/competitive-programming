#include <bits/stdc++.h>
#define MAX 1010
using namespace std;
char square[MAX][MAX];

bool isLand(char block){
    return block=='#';
}

int n, m, ans;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> square[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(isLand(square[i][j])){
                if(i==0 || i==n-1 || j==0 || j==m-1)
                    ans++;
                else{
                    if(!(isLand(square[i+1][j]) && isLand(square[i][j+1]) && isLand(square[i-1][j]) && isLand(square[i][j-1])))
                        ans++;
                }
            }
        }
    }
    cout << ans;
}