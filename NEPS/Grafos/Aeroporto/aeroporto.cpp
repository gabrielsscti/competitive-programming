#include <bits/stdc++.h>
using namespace std;

int trafegoAeroporto[110];

int main(){
    int a, v, teste=0;
    cin >> a >> v;
    while(a!=0 && v!=0){
        memset(trafegoAeroporto, 0, sizeof(trafegoAeroporto));
        for(int i=0; i<v; i++){
            int x, y;
            cin >> x >> y;
            trafegoAeroporto[x-1]++;
            trafegoAeroporto[y-1]++;

        }
        int largerTraffic = -1;
        vector<int> r;
        for(int i=0; i<a; i++){
            if(trafegoAeroporto[i]>largerTraffic){
                r.clear();
                r.push_back(i+1);
                largerTraffic = trafegoAeroporto[i];
            }else if(trafegoAeroporto[i]==largerTraffic){
                r.push_back(i+1);
            }
        }
        cout << "Teste " << ++teste << endl;
        auto it = r.begin();
        while(it!=r.end()){
            cout << *it << " ";
            it++;
        }
        cout << endl;
        cin >> a >> v;
    }
}