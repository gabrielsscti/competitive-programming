/*
Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931
Autor: Gabriel Sousa Silva Costa
Site: http://github.com/gabrielsscti
*/

#include <bits/stdc++.h>
#define MAX 10100

using namespace std;

typedef struct _caminho_{
    int pesoAresta, dest, paridade;
    bool operator<(const _caminho_& rhs) const{
        return pesoAresta<rhs.pesoAresta;
    }
}Caminho;

vector<Caminho> adj[MAX];
bool visited[2][MAX];
int dist[2][MAX];
int c, v;

int solve(int n){
    dist[0][n] = 0;
    priority_queue<Caminho> frontier;
    frontier.push({n, dist[0][n], 0});
    while(true){
        int actNode = -1, actParidade = 0, nextParidade = 0;
        while(!frontier.empty()){
            Caminho tempCaminho = frontier.top();
            if(!visited[tempCaminho.dest]){
                actNode = tempCaminho.dest;
                actParidade = tempCaminho.paridade;
                nextParidade = (actParidade+1)%2;
                break;
            }
        }
        if(actNode==-1)
            break;
        for(int i=0; i<adj[actNode].size(); i++){
            int actDist = adj[actNode][i].pesoAresta;
            int actDest = adj[actNode][i].dest;
            if(dist[nextParidade][actDest]==-1 || dist[nextParidade][actDest]>dist[actParidade][actNode]+actDist){
                dist[nextParidade][actDest] = dist[actParidade][actNode]+actDist;
                frontier.push({actDest, dist[nextParidade][actDest], nextParidade});
            }
        }
    }
    return dist[0][c-1];
}

int main(){
    memset(dist, -1, sizeof(dist));
    cin >> c >> v;
    for(int i=0; i<v; i++){
        int c1, c2, g;
        cin >> c1 >> c2 >> g;
        c1--, c2--;
        adj[c1].push_back({c2, g});
    }
    cout << solve(0) << endl;
}