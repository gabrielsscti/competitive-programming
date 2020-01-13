#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int solve(int *v){
    vector<int> pilha;
    for(int i=0; i<MAX; i++){
        auto it = lower_bound(pilha.begin(), pilha.end(), v[i]);
        if(it==pilha.end())
            pilha.push_back(v[i]);
        else
            *it = v[i];
    }
    return pilha.size();
}

int v[MAX];

int main(){
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
        v[i] = rand()%100;
    cout << "Longest Increasing Subsequence for" << endl;
    for(int i=0; i<MAX; i++)
        cout << v[i] << " ";
    cout << endl << "is: " << solve(v) << endl;
}