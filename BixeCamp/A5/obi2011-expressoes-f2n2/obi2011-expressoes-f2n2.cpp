#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
	cin >> t;
	while(t--){
		bool valid = true;
		stack<char> st;
		string s;
		cin >> s;
		for(char c : s){
			char topElement = st.empty() ? ' ' : st.top();
			if(st.empty() && (c=='}' || c==']' || c==')')){
				valid = false;
				break;
			}	
			else if(st.empty() || c=='{' || c=='[' || c=='(')
				st.push(c);
			else if(topElement=='{'){
				if(c=='}')
					st.pop();
				else{
					valid = false;
					break;
				}
			}
			else if(topElement=='['){
				if(c==']')
					st.pop();
				else{
					valid = false;
					break;
				}
			}
			else if(topElement=='('){
				if(c==')')
					st.pop();
				else{
					valid = false;
					break;
				}
			}
		}
		cout << (valid && st.empty() ? "S" : "N") << endl;

	}
	return 0;
}
