#include <bits/stdc++.h>
#define MAX 10
#define kappa() cout << "KAPPA" << endl
using namespace std;

vector<int> solve(int *v){
    vector<int> pilha;
    int pai[MAX], pos[MAX];
    for(int i=0; i<MAX; i++){
        auto it = lower_bound(pilha.begin(), pilha.end(), v[i]);

        int actPilha = it-pilha.begin();

        if(it==pilha.end())
            pilha.push_back(v[i]);
        else
            *it = v[i];

        pos[actPilha] = i;
        if(actPilha==0)
            pai[i] = -1;
        else
            pai[i] = pos[actPilha-1];
        
        
    }
    vector<int> res;
    int temp = pos[pilha.size()-1];
    while(temp>=0){
        res.push_back(v[temp]);
        temp = pai[temp];
    }
    reverse(res.begin(), res.end());
    return res;
}

int v[MAX];

int main(){
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
        v[i] = rand()%100;
    cout << "Longest Increasing Subsequence for" << endl;
    for(int i=0; i<MAX; i++)
        cout << v[i] << " ";
    cout << endl << "is: " << endl;
    vector<int> r = solve(v);
    for(int i=0; i<r.size(); i++)
        cout << r[i] << " ";
}