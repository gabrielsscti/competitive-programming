#include <bits/stdc++.h>
#define MAX 100
using namespace std;

vector<int> adj[MAX+10];
bool visited[MAX+10];
int n, test;

int dfs(int x){
    int length = 0;
    visited[x] = true;
    for(int i=0; i<adj[x].size(); i++){
        int temp = adj[x][i];
        if(!visited[temp])
            length = max(length, 1 + dfs(temp));
        
    }
    return length;
}

int main(){
    cin >> n;
    while(n!=0){
        for(int i=0; i<n-1; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int smallestPath = INT_MAX, ans = 1; 
        for(int i=1; i<=n; i++){
            memset(visited, false, sizeof(visited));
            int temp = dfs(i);
            if(temp<smallestPath){
                smallestPath = temp;
                ans = i;
            }
        }
        cout << "Teste " << ++test << endl << ans << endl;
        for(int i=1; i<=n; i++)
            adj[i].clear();
        cin >> n;

    }
}