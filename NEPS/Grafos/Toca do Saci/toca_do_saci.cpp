#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int blocks[MAX][MAX];
int n, m;
int startingPointX, startingPointY;

bool indexExists(int index, int limit){
    return (index>=0 && index<limit);
}

bool isPath(int x, int y){
    return (blocks[x][y]==1 || blocks[x][y]==2);
}

int solve(int x, int y){
    if(blocks[x][y]==2)
        return 1;
    else{
        blocks[x][y]=0;
        if(indexExists(x-1, n)){
            if(isPath(x-1, y))
                return 1+solve(x-1, y);
        }
        if(indexExists(x+1, n)){
            if(isPath(x+1, y))
                return 1+solve(x+1, y);
        }
        if(indexExists(y-1, m)){
            if(isPath(x, y-1))
                return 1+solve(x, y-1);
        }
        if(indexExists(y+1, m)){
            if(isPath(x, y+1))
                return 1+solve(x, y+1);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> blocks[i][j];
            if(blocks[i][j]==3){
                startingPointX = i;
                startingPointY = j;
            }
        }
    }
    cout << solve(startingPointX, startingPointY) << endl;
}