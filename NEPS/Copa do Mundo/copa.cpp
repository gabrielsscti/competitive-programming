#include <bits/stdc++.h>

using namespace std;

queue<char> teams;
queue<pair<int, int>> resultado;
int quantTeams = 16;

int main(){
    for(int i=0; i<quantTeams; i++)
        teams.push('A'+i);
    for(int i=0; i<15; i++){
        int m, n;
        cin >> m >> n;
        resultado.push(make_pair(m, n));
    }
    while(quantTeams!=1){
        for(int i=0; i<quantTeams/2; i++){
            pair<int, int> temp = resultado.front();
            resultado.pop();
            if(temp.first>temp.second){
                teams.push(teams.front());
                teams.pop();
                teams.pop();
            }else{
                teams.pop();
                teams.push(teams.front());
                teams.pop();
            }
        }
        quantTeams/=2;
    }
    cout << teams.front() << endl;

}