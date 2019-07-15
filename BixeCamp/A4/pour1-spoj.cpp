#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int solve(int a, int b,int c){//a<b
	if((b<c && a<c) || c%gcd(min(a, b), max(a, b))!=0)
		return -1;
	if(c==a || c==b)
		return 1;
	int x=0, y=0, r1=0, r2=0;

	while(true){
		if(x==0){
			x=a;
			r1++;
		}
		if(y==b){
			y=0;
			r1++;
		}
		if(x+y>b){
			x -= b-y;
			y = b;
			r1++;
		}else{
			y = y+x;
			x = 0;
			r1++;
		}
		if(y==c || x==c)
			break;
	}
	x=0, y=0;
	while(true){
		if(y==0){
			y=b;
			r2++;
		}
		if(x==a){
			x=0;
			r2++;
		}
		if(x+y>a){
			y -= a-x;
			x = a;
			r2++;
		}else{
			x = y+x;
			y = 0;
			r2++;
		}
		if(x==c || y==c)
			break;
	
	}
	return min(r1, r2);
}
	
int a, b, c, t;

int main(){
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> a >> b >> c;
		cout << solve(min(a, b), max(a, b), c) << endl;
	}
	return 0;
}
