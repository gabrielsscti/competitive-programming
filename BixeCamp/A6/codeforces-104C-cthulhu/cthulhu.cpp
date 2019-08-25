#include <bits/stdc++.h>

using namespace std;

vector<int> adj[110];
bool visited[110][110];
bool verticeVisited[110];
int n, m;

int getContinuousEdgeCount(int x){
    verticeVisited[x] = true;
    int size=0;
    for(int i=0; i<adj[x].size(); i++){
        if(!visited[x][adj[x][i]]){
            visited[x][adj[x][i]] = true;
            visited[adj[x][i]][x] = true;
            size += 1+getContinuousEdgeCount(adj[x][i]);
        }
        
    }
    return size;
}

bool isAllVerticeVisited(){
    for(int i=1; i<=n; i++)
        if(!verticeVisited[i])
            return false;
    return true;
}

int main(){
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    memset(verticeVisited, false, sizeof(verticeVisited));
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(getContinuousEdgeCount(1)==n && n==m && isAllVerticeVisited())
        cout << "FHTAGN!" << endl;
    else
        cout << "NO" << endl;
}