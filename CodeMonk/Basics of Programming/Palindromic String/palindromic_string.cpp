#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    bool isPalindrome = true;
    cin >> s;
    for(int i=0, j=s.length()-1; i<s.length(); i++, j--){
        if(s[i]!=s[j])
            isPalindrome = false;
    }
    cout << (isPalindrome ? "YES" : "NO") << endl;
}