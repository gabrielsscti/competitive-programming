#include <bits/stdc++.h>
#define INF INT32_MAX

using namespace std;

typedef struct _estrada_{
    int dest, dist;
    bool operator<(const _estrada_& rhs) const{
        return dist < rhs.dist;
    }
} Estrada;
typedef pair<int, int> pii;

int n, m, c, k;
vector<Estrada> estradas[260];
int dist[260];
bool processado[260];


void dijkstra(int origin){
    dist[origin] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push(make_pair(dist[origin], origin));
    while(true){
        int inturn = -1;
        while(!fila.empty()){
            int nextVertex = fila.top().second;
            fila.pop();
            if(!processado[nextVertex]){
                inturn = nextVertex;
                break;
            }
        }
        if(inturn == -1)
            break;
        processado[inturn] = true;

        for(int i=0; i<estradas[inturn].size(); i++){
            int actDist = estradas[inturn][i].dist;
            int actDest = estradas[inturn][i].dest;
            //cout << "On node " << inturn << " to dest " << actDest << " with distance " << actDist << " comparing " << dist[actDest] << " with " << dist[inturn]+actDist<< endl;
            if(inturn>=c){
                if(dist[actDest]>dist[inturn]+actDist){
                    dist[actDest] = dist[inturn]+actDist;
                    fila.push(make_pair(dist[actDest], actDest));
                }
            }
            else{
                if((inturn==actDest+1 || inturn==actDest-1) && (actDest<c)){
                    if(dist[actDest]>dist[inturn]+actDist){
                        dist[actDest] = dist[inturn]+actDist;
                        fila.push(make_pair(dist[actDest], actDest));
                    }
                }
            }
        }
    }
}

void resetData(){
    for(int i=0; i<260; i++){
        estradas[i].clear();
        dist[i] = INF;
        processado[i] = false;
    }
}

int main(){
    cin >> n >> m >> c >> k;
    for(int i=0; i<n; i++)
        dist[i] = INF;
    while(n!=0 || m!=0 || c !=0 || k!=0){
        for(int i=0; i<m; i++){
            int u, v, p;
            cin >> u >> v >> p;
            estradas[u].push_back({v, p});
            estradas[v].push_back({u, p});
        }
        dijkstra(k);
        cout << dist[c-1] << endl;
        resetData();
        cin >> n >> m >> c >> k;
    }
}