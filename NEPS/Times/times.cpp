#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int n, t;
vector<pair<int, string>> jogadores;
vector<string> times[1010];

int main(){
    cin >> n >> t;
    for(int i=0; i<n; i++){
        string nome;
        int habilidade;
        cin >> nome >> habilidade;
        jogadores.push_back(make_pair(habilidade, nome));
    }
    sort(jogadores.begin(), jogadores.end());
    int actTeam = -1;
    while(!jogadores.empty()){
        actTeam++;
        string name = jogadores.back().second;
        jogadores.pop_back();
        times[actTeam].push_back(name);
        if(actTeam==t-1)
            actTeam = -1;
    }
    for(int i=0; i<t; i++){
        cout << "Time " << i+1 << endl;
        sort(times[i].begin(), times[i].end());
        for(int j=0; j<times[i].size(); j++)
            cout << times[i][j] << endl;
        cout << endl;
        
    }
}