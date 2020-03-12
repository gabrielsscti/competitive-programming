/*
Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931
Autor: Gabriel Sousa Silva Costa
Site: http://github.com/gabrielsscti
*/

#include <bits/stdc++.h>
#define MAX 10100

using namespace std;

vector<pair<int, int>> adj[MAX];
bool visited[2][MAX];
int result[2][MAX];
int c, v;

typedef struct _frontiernode_{
    int to, distance, parity;
    bool operator<(const _frontiernode_& rhs) const{
        return distance>rhs.distance;
    }
}FrontierNode;

int solve(int from, int to){
    priority_queue<FrontierNode> frontier;
    frontier.push({from, 0, 0});
    result[0][from] = 0;
    while(!frontier.empty()){
        FrontierNode actNode = frontier.top();
        frontier.pop();
        int to=actNode.to, distance=actNode.distance, parity=actNode.parity;
        bool *actVisited = &visited[parity][to];
        if(!(*actVisited)){
            *actVisited = true;
            for(pair<int, int> ngbr : adj[to]){
                int newParity = (parity+1)%2;
                int newDistance = distance + ngbr.second;
                int *actDistance = &result[newParity][ngbr.first];
                if(newDistance < *actDistance){
                    *actDistance = newDistance;
                    frontier.push({ngbr.first, *actDistance, newParity});
                }
            }
        }
    }
    return (result[0][to]==INT32_MAX ? -1 : result[0][to]);
}

int main(){
    for(int i=0; i<2; i++)
        for(int j=0; j<MAX; j++)
            result[i][j] = INT32_MAX;
    cin >> c >> v;
    for(int i=0; i<v; i++){
        int from, to, dist;
        cin >> from >> to >> dist;
        adj[from].push_back(make_pair(to, dist));
        adj[to].push_back(make_pair(from, dist));

    }
    cout << solve(1, c) << endl;
}