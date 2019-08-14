#include <bits/stdc++.h>
using namespace std;

map<int, int> votos;

int main(){
    int n;
    cin >> n;
    while(n--){
        int voto;
        cin >> voto;
        auto it = votos.find(voto);
        if(it!=votos.end()){
            it->second++;
        }else{
            votos.insert(pair<int, int>(voto, 1));
        }
    }
    auto it = votos.begin();
    pair<int, int> maxVoto(it->first, it->second);
    while(it!=votos.end()){
        if(it->second > maxVoto.second)
            maxVoto.first = it->first, maxVoto.second = it->second;
        it++;
    }
    cout << maxVoto.first << endl;
    

}