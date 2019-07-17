#include <bits/stdc++.h>
using namespace std;

int n;
long long int a[200100];

int main(){
	cin >> n;
	bool isAlreadyCompleted=false;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(i!=0)
			if(a[i]!=a[i-1])
				isAlreadyCompleted = false;
	}
	if(!isAlreadyCompleted){
		for(int i=0; i<n; i++){
			if(i!=n-1){
				while(a[i]<a[i+1])
					a[i]+=2;
				while(a[i]==a[i+1]
			}
		
		}
	}else
		cout << "YES" << endl;



}
