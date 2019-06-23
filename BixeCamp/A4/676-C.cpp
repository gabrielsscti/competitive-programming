#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int getAnswer(string s, char c){
    int i=0, j=0, r=0, remainingChanges = k;
    while(j!=n){
        
        if(s[j]!=c){
            r = max(r, j-i+1);
            j++;
            //r = max(r, j-i+1);
        }
        if(s[j]==c){
            if(remainingChanges!=0){
                r = max(r, j-i+1);
                remainingChanges--, j++;
            }else{
                if(s[i]==c)
                    remainingChanges++;
                i++;
            }
        }
        
    }
    return r;
}

int main(){
    cin >> n >> k;
    cin >> s;
    
    cout << max(getAnswer(s, 'a'), getAnswer(s, 'b'));

}