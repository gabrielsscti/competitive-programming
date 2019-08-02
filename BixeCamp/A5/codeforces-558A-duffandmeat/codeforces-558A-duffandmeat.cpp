#include <bits/stdc++.h>

using namespace std;

int n, r=0;
int a[100100], p[100100];


int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		cin >> p[i];
	
	}
	int i=0;
	while(i<n){
		int j=i;
		bool enteredWhile = false;
		while(j<n & p[i]<=p[j]){
			r += p[i]*a[j];
			j++;
			enteredWhile = true;
		}
		i=j;
		if(!enteredWhile) i=j+1;
	}
	cout << r << endl;

}
