#include <bits/stdc++.h>

using namespace std;

string var[120][120];
int lineSum[120], colSum[120];
int l, c;

void update(string &found, int val){
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            if(var[i][j]==found){
                lineSum[i] -= val;
                colSum[j] -= val;
            }
        }
    }
}

int main(){
    cin >> l >> c;
    set<string> unknown;
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin >> var[i][j];
            unknown.insert(var[i][j]);
        }
        cin >> lineSum[i];
    }
    for(int j=0; j<c; j++)
        cin >> colSum[j];

    map<string, int> known;
    while(known.size()!=unknown.size()){
        for(int i=0; i<l; i++){
            set<string> unk;
            int times = 0;
            for(int j=0; j<c; j++){
                if(!known.count(var[i][j])){
                    times++;
                    unk.insert(var[i][j]);
                }
            }
            if(unk.size()==1){
                string found = *unk.begin();
                known[found] = lineSum[i]/times;
                update(found, known[found]);
            }
        }
        for(int j=0; j<c; j++){
            set<string> unk;
            int times = 0;
            for(int i=0; i<l; i++){
                if(!known.count(var[i][j])){
                    times++;
                    unk.insert(var[i][j]);
                }
            }
            if(unk.size()==1){
                string found = *unk.begin();
                known[found] = colSum[j] / times;
                update(found, known[found]);
                break;
            }
        }
    }
    for(auto &res : known)
        cout << res.first << " " << res.second << endl;
    
    return 0;
}