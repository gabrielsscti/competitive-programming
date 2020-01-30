#include <bits/stdc++.h>

using namespace std;

int n, d, removidos;
stack<char> ans;

int main(){
    while(cin >> n >> d && (n+d)!=0){
        for(int i=0; i<n; i++){
            char algarism;
            cin >> algarism;
            while(!ans.empty() && algarism > ans.top() && removidos < d){
                ans.pop();
                removidos++;
            }
            if(ans.size() < n-d) ans.push(algarism);
        }
        stack<char> r;
        while(!ans.empty()){
            r.push(ans.top());
            ans.pop();
        }
        while(!r.empty())
            cout << r.top(), r.pop();
        cout << endl;
        removidos = 0;
    }

    return 0;
}
