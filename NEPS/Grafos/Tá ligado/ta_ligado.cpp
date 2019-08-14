#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int> adj[MAX];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t==0){
            if(find(adj[a].begin(), adj[a].end(), b)==adj[a].end())
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }else{
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
    }
    return 0;
}