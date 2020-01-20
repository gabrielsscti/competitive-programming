#include <bits/stdc++.h>
#define MAX 100000

int m, r;
int v[MAX];

using namespace std;

int *solve(int *v){
    vector<int> stacks;
    int *res = (int*)malloc(sizeof(int)*m);
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
            pai[i] = pos[actStack-1];
    }
    for(int i=0; i<m; i++){
        int temp = pai[i];
        int r = 1;
        while(temp>=0){
            r++;
            temp = pai[temp];
        }
        res[i] = r;
    }
    return res;
    
}

int main(){
    cin >> m;
    for(int i=0; i<m; i++)
        cin >> v[i];
    int *incSeq = solve(v);
    reverse(v, v+m);
    int *decSeq = solve(v);
    reverse(decSeq, decSeq+m);
    // for(int i=0; i<m; i++)
    //     cout << incSeq[i] << "\t";
    // cout << endl;
    // for(int i=0; i<m; i++)
    //     cout << decSeq[i] << "\t";
    // cout << endl;
    for(int i=0; i<m; i++)
        r = max(r, min(incSeq[i], decSeq[i]));
    cout << 2*(r-1)+1 << endl;
    
    
}