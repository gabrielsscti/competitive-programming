#include <bits/stdc++.h>
#define MAX 110
#define INF INT32_MAX

using namespace std;

int n;
int mina[MAX][MAX];
int distancia[MAX][MAX];
bool processado[MAX][MAX];
int *limitsX;
int *limitsY;
int movesX[4] = {1, -1, 0, 0};
int movesY[4] = {0, 0, 1, -1};

typedef struct _ponto_{
    int x, y;
    bool operator<(const _ponto_& rhs) const{
        return distancia[x][y] > distancia[rhs.x][rhs.y];
    }
}Ponto;

bool isOffset(Ponto c){
    for(int i=0; i<4; i++){
        if(c.x==limitsX[i] || c.y==limitsY[i])
            return true;
    }
    return false;
}

bool isCoordValid(Ponto c){
    return !(c.x==-1 | c.y==-1);
}

Ponto getVertex(int x, int y){
    return {x, y};
}

int getDistance(Ponto c){
    return distancia[c.x][c.y];
}

void setDistance(Ponto c, int val){
    distancia[c.x][c.y] = val;
}

int dijkstra(Ponto c){
    setDistance(c, 0);
    priority_queue<Ponto> fila;
    fila.push(c);
    while(true){
        Ponto act = {-1, -1};
        int smaller = INF;
        while(!fila.empty()){
            Ponto actVertice = fila.top();
            fila.pop();
            if(!processado[actVertice.x][actVertice.y]){
                act = actVertice;
                break;
            }
        }
        if(!isCoordValid(act))
            break;
        processado[act.x][act.y] = true;
        for(int i=0; i<4; i++){
            Ponto actVertex = getVertex(act.x + movesX[i], act.y + movesY[i]);
            if(!isOffset(actVertex)){
                int weight = mina[actVertex.x][actVertex.y];
                if(getDistance(actVertex) > getDistance(act) + weight){
                    setDistance(actVertex, getDistance(act)+weight);
                    fila.push(actVertex);
                }
            }
        }
    }
}

int main(){
    cin >> n;
    int tempLimitsX[] = {-1, n, -1, n};
    int tempLimitsY[] = {-1, -1, n, n};
    limitsX = tempLimitsX;
    limitsY = tempLimitsY;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            mina[i][j] = temp;
            distancia[i][j] = INF;
            processado[i][j] = false;
        }
    dijkstra({0, 0});
    cout << distancia[n-1][n-1] << endl;
    return 0;
    
}