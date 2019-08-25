#include <bits/stdc++.h>
using namespace std;

char maze[510][510];
pair<int, int> emptyCell[510*510];
bool visited[510][510];
int n, m, k, emptyCellCount, transformedCellCount, reach;

bool isPosValid(int pos, int limit){
    return (pos>=0 && pos<limit);
}

void dfs(int x, int y){
    reach++;
    visited[x][y] = true;
    if(reach>emptyCellCount-k)
        maze[x][y] = 'X';
    if(isPosValid(x-1, n) && maze[x-1][y]=='.' && !visited[x-1][y])
        dfs(x-1, y);
    if(isPosValid(x+1, n) && maze[x+1][y]=='.' && !visited[x+1][y])
        dfs(x+1, y);
    if(isPosValid(y-1, m) && maze[x][y-1]=='.' && !visited[x][y-1])
        dfs(x, y-1);
    if(isPosValid(y+1, m) && maze[x][y+1]=='.' && !visited[x][y+1])
        dfs(x, y+1);
    return;
    
}

int main(){
    cin >> n >> m >> k;
    memset(visited, false, sizeof(visited));
    int tempX=-1, tempY=-1;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            char temp;
            cin >> temp;
            maze[i][j] = temp;
            if(temp=='.'){
                emptyCellCount++;
                if(tempX==-1){
                    tempX = i;
                    tempY = j;
                }
            }
        }
    dfs(tempX, tempY);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << maze[i][j];
        cout << endl;
    }


}