#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

vector<int> adj[MAX+10];
int component[MAX+10];
int n, m, ans;

bool setComponents(int x, int actComponent){
    component[x] = actComponent;
    bool isCycle = (adj[x].size()==2 ? true : false);
    for(int i=0; i<adj[x].size(); i++){
        if(component[adj[x][i]]==-1)
            isCycle = isCycle & setComponents(adj[x][i], actComponent);
    }
    return isCycle;
}

int main(){
    memset(component, -1, sizeof(component));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int actComponent = 1;
    for(int i=1; i<=n; i++){
        if(component[i]==-1){
            if(setComponents(i, actComponent))
                ans++;
        }
        actComponent++;
    }
    cout << ans;
}