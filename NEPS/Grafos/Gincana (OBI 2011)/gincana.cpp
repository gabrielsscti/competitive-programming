#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1010];
int component[1010];
int actComponent;

void dfs(int x){
    for(int i=0; i<adj[x].size(); i++){
        if(component[adj[x][i]]==-1){
            component[adj[x][i]] = component[x];
            dfs(adj[x][i]);
        }
    }
}

int main(){
    cin >> n >> m;
    memset(component, -1, sizeof(component));
    for(int i=0; i<m; i++){
        int p1, p2; cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);

    }

    for(int i=1; i<=n; i++){
        if(component[i]==-1){
            component[i] = ++actComponent;
            dfs(i);
        }
    }
    cout << actComponent << endl;
}