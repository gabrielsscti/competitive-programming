#include <bits/stdc++.h>
#define MAX 100100

using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
bool hasCat[MAX];
int n, m, ans;

void dfs(int x, int catNumber){
    visited[x] = true;
    catNumber = (hasCat[x] ? catNumber+1 : (catNumber>m ? catNumber : 0));
    if(x!=1 && adj[x].size()==1)
        if(catNumber<=m)
            ans++;
    for(int i=0; i<adj[x].size(); i++){
        if(!visited[adj[x][i]])
            dfs(adj[x][i], catNumber);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        hasCat[i+1] = temp;
    }
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;

}