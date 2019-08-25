#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
int n;
int largestNode, largestNodeLength=-1;

void dfs(int x, int length){
    visited[x] = true;
    for(int i=0; i<adj[x].size(); i++){
        if(!visited[adj[x][i]])
            dfs(adj[x][i], 1+length);
    }
    if(length>largestNodeLength){
        largestNodeLength = length;
        largestNode = x;
    }

}

int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(largestNode, 0);
    cout << largestNodeLength << endl;

}