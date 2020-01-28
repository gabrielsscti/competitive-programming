#include <bits/stdc++.h>
using namespace std;

int p, s;
pair<int, int> intervalos[5010];

int main(){
    cin >> p >> s;
    for(int i=0; i<s; i++){
        int u, v;
        cin >> u >> v;
        intervalos[i] = make_pair(u, v);
    }
    sort(intervalos, intervalos+s);
    vector<pair<int, int>> r;
    int actStart = intervalos[0].first, actEnd = intervalos[0].second;
    for(int i=0; i<s; i++){
        if(intervalos[i].first <= actEnd)
            actEnd = max(intervalos[i].second, actEnd);
        else{
            r.push_back(make_pair(actStart, actEnd));
            actStart = intervalos[i].first, actEnd = intervalos[i].second;
        }
    }
    r.push_back(make_pair(actStart, actEnd));
    for(int i=0; i<r.size(); i++)
        cout << r[i].first << " " << r[i].second << endl;
    
}