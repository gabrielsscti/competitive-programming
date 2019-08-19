#include <bits/stdc++.h>
using namespace std;

bool visited[100100];
int branchSize[100100];
vector<int> adj[100100];
vector<int> pathLength;



int getBranchSize(int x){
    if(branchSize[x]!=-1)
        return branchSize[x];
    else{
        if(adj[x].size()==0){
            return branchSize[x] = 1;
        }
        else{
            int tempSize = 1;
            for(int i=0; i<adj[x].size(); i++)
                tempSize += getBranchSize(adj[x][i]);
            return branchSize[x] = tempSize;
        }
    }
}

bool areSonEquals(int x){
    bool ans = true;
    int comparator;
    if(adj[x].size()!=0)
        comparator = getBranchSize(adj[x][0]);
    for(int i=0; i<adj[x].size(); i++){
        if(getBranchSize(adj[x][i])!=comparator)
            ans = false;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    memset(branchSize, -1, sizeof(branchSize));
    for(int i=0; i<n; i++){
        int peca1, peca2;
        cin >> peca1 >> peca2;
        adj[peca2].push_back(peca1);
    }
    bool ans = true;
    for(int i=0; i<=n; i++)
        ans = ans && areSonEquals(i);
    cout << (ans ? "bem" : "mal") << endl;
    return 0;
}