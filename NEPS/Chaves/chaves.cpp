#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    stack<char> ans;
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        for(int i=0; i<line.size(); i++){
            if(line[i]=='{')
                ans.push(line[i]);
            else if(line[i]=='}'){
                if(ans.empty())
                    ans.push(line[i]);
                else{
                    if(ans.top()=='{')
                        ans.pop();
                }
                
            }
        }
    }
    if(ans.empty())
        cout << "S" << endl;
    else
        cout << "N" << endl;
}