#include <bits/stdc++.h>
using namespace std;

int n;
long long int a[200100];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i] &= 1;
	}
	vector<int> st;
	for(int i=0; i<n; i++){
		if(!st.empty() && a[i]==st.back()){
			st.pop_back();
		}else{
			st.push_back(a[i]);

		}
	}
	cout << (st.size() <= 1 ? "YES" : "NO") << endl;
}
