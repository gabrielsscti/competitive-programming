/*
Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931
Autor: Gabriel Sousa Silva Costa
Site: http://github.com/gabrielsscti
*/

#include <bits/stdc++.h>
#define MAX 10100

using namespace std;

typedef long long int lli;

typedef struct _caminho_{
    int dest, pesoAresta, paridade;
    bool operator<(const _caminho_& rhs) const{
        return pesoAresta<rhs.pesoAresta;
    }
}Caminho;

vector<Caminho> adj[MAX];
bool visited[2][MAX];
lli dist[2][MAX];
int c, v;

lli solve(int n){
    dist[0][n] = 0;
    priority_queue<Caminho> frontier;
    frontier.push({n, 0, 0});
    while(true){
        int actNode = -1, actParidade = 0, nextParidade = 0;
        while(!frontier.empty()){
            Caminho tempCaminho = frontier.top();
            frontier.pop();
            if(!visited[tempCaminho.paridade][tempCaminho.dest]){
                actNode = tempCaminho.dest;
                actParidade = tempCaminho.paridade;
                nextParidade = (actParidade+1)%2;
                break;
            }
        }
        if(actNode==-1)
            break;
        visited[actParidade][actNode] = true;
        for(int i=0; i<adj[actNode].size(); i++){
            int actDist = adj[actNode][i].pesoAresta;
            int actDest = adj[actNode][i].dest;
            if(dist[nextParidade][actDest]>dist[actParidade][actNode]+actDist){
                dist[nextParidade][actDest] = dist[actParidade][actNode]+actDist;
                frontier.push({actDest, actDist, nextParidade});
            }
        }
    }
    return (dist[0][c-1]==INT64_MAX ? -1 : dist[0][c-1]);
}

int main(){
    for(int i=0; i<2; i++){
        for(int j=0; j<MAX; j++){
            dist[i][j] = INT64_MAX;
        }
    }
    cin >> c >> v;
    for(int i=0; i<v; i++){
        int c1, c2, g;
        cin >> c1 >> c2 >> g;
        c1--, c2--;
        adj[c1].push_back({c2, g, 0});
        adj[c2].push_back({c1, g, 0});
    }
    cout << solve(0) << endl;
}