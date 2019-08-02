#include <bits/stdc++.h>

using namespace std;

int n;
int mobil[1010];

int main(){
	cin >> n;
	while(n!=0){
		int actBus = 1;
		stack<int> st;
		vector<int> r;
		for(int i=0; i<n; i++)
			cin >> mobil[i];

		for(int i=0; i<n; i++){
			if(mobil[i]!=actBus){
				st.push(mobil[i]);
			}
			else{
				r.push_back(mobil[i]);
				actBus++;
			}
			while(!st.empty() && st.top()==actBus){
				r.push_back(st.top());
				st.pop();
				actBus++;	
			}
		}
		/*while(!st.empty()){
			cout << st.top() << endl;
			st.pop();
		}*/
		cout << ((is_sorted(r.begin(), r.end()) && st.empty()) ? "yes" : "no") << endl;
		cin >> n;
	}
	return 0;
}
