#include <bits/stdc++.h>

using namespace std;

int solve(string s){
    vector<int> stacks;
    for(int i=0; i<s.size(); i++){
        int temp = (int)s[i];
        auto it = upper_bound(stacks.begin(), stacks.end(), temp);
        if(it==stacks.end())
            stacks.push_back(temp);
        else
            *it = temp;

    }
    return stacks.size();
}

int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;
}