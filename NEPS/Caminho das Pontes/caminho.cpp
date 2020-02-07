#include <bits/stdc++.h>
#define MAX 1010
#define INF INT32_MAX

using namespace std;

typedef pair<int, int> pii;

typedef struct _caminho_{
    int adj;
    int buracos;
    bool operator<(const _caminho_& rhs) const{
        return buracos < rhs.buracos;
    }
} Caminho;

int n, m;
vector<Caminho> adj[MAX];
bool processado[MAX];
int distancia[MAX];

void dijkstra(int pilar){
    distancia[pilar] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push(pii(distancia[pilar], pilar));
    while(true){
        int inturn = -1;
        int menor = INF;
        while(!fila.empty()){
            int act = fila.top().second;
            fila.pop();
            if(!processado[act]){
                inturn = act;
                break;
            }
        }
        if(inturn == -1)
            break;
        processado[inturn] = true;
        
        for(int i=0; i<adj[inturn].size(); i++){
            int dist = adj[inturn][i].buracos;
            int act = adj[inturn][i].adj;
            if(distancia[act]>distancia[inturn] + dist){
                distancia[act] = distancia[inturn] + dist;
                fila.push(make_pair(distancia[act], act));
                
            }
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i=0; i<=n+1; i++){
        distancia[i] = INF;
        processado[i] = false;
    }
    for(int i=0; i<m; i++){
        int s, t, b;
        cin >> s >> t >> b;
        adj[s].push_back({t, b});
        adj[t].push_back({s, b});

    }
    dijkstra(0);
    cout << distancia[n+1] << endl;
}