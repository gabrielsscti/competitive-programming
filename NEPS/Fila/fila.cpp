#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        auto it = find(v.begin(), v.end(), temp);
        v.erase(it);
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    
}