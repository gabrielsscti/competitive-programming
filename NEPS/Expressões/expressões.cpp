#include <bits/stdc++.h>

using namespace std;

int t;

bool isOpeningChar(char s){
    return (s=='(' || s=='[' || s=='{');
}

bool isCorrespondingChar(char newChar, char testChar){
    if(newChar == ')')
        return (testChar == '(');
    if(newChar == ']')
        return (testChar == '[');
    if(newChar == '}')
        return (testChar == '{');
    return false;
}

int main(){
    cin >> t;
    while(t--){
        string expression;
        cin >> expression;
        stack<char> r;
        for(int i=0; i<expression.size(); i++){
            char actChar = expression[i];
            if(isOpeningChar(actChar))
                r.push(actChar);
            else{
                if(r.empty()){
                    r.push(actChar);
                    break;
                }
                else{
                    if(isCorrespondingChar(actChar, r.top()))
                        r.pop();
                    
                    else
                        break;
                    
                }
            }
        }
        if(r.empty())
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
}