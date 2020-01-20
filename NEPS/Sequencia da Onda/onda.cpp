#include <bits/stdc++.h>
#define MAX 100000

int m;
int v[MAX];

using namespace std;

pair<int, int*> solve(int *v){
    vector<int> stacks;
    int pos[MAX], pai[MAX];
    for(int i=0; i<m; i++){
        auto it = lower_bound(stacks.begin(), stacks.end(), v[i]);
        int actStack = it-stacks.begin();

        if(it==stacks.end())
            stacks.push_back(v[i]);
        else
            *it = v[i];

        pos[actStack] = i;
        
        if(!actStack)
            pai[i] = -1;
        else
            pai[i] = stacks[actStack-1];
         
    }
    pair<int, int*> r = {stacks.size(), pos};
    return r;
}

int main(){
    cin >> m;
    for(int i=0; i<m; i++)
        cin >> v[i];
    pair<int, int*> ans = solve(v);
    int r = 1;
    
    
}