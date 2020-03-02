#include <bits/stdc++.h>
#define MAX 510
using namespace std;

int n, m;
bool explorado[MAX];

typedef struct _aresta_{
    int c1, c2, comprimento;
    bool operator<(const _aresta_& rhs) const{
        return comprimento > rhs.comprimento;
    }
}Aresta;

priority_queue<Aresta> cidades;

int pai[MAX], peso[MAX];

int find(int x){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}

int kruskall(){
    int r = 0;

    while(!cidades.empty()){
        Aresta arestaAtual = cidades.top();
        cidades.pop();
        int aresta1 = arestaAtual.c1, aresta2 = arestaAtual.c2, actComprimento = arestaAtual.comprimento;
        if(find(aresta1) != find(aresta2)){
            join(aresta1, aresta2);
            r += actComprimento;
        }
    }
    return r;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        cidades.push({u, v, c});
    }
    for(int i=1; i<=n; i++) pai[i] = i;

    cout << kruskall() << endl;
}