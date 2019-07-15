#include <bits/stdc++.h>

using namespace std;

int n;
int wine[100100];

void debug(int a, int b){
	cout << a << "\t" << b << "\t" << endl; 
}

int processBuy(int buying, int selling){
	selling = abs(selling);
	return min(buying, selling);
}

int main(){
	cin >> n;
	while(n!=0){
		long long int ans=0;
		int actIndex = 0;
		for(int i=0; i<n; i++){
			cin >> wine[i];
			
		}
		int i = 1;
		while(actIndex!=n){
			if(i==actIndex)
				i++;
			if((wine[i]>0 && wine[actIndex]<0) || (wine[i]<0 && wine[actIndex]>0)){
				int exchanged = processBuy(max(wine[i], wine[actIndex]), min(wine[i], wine[actIndex]));
				if(wine[i]<0)
					wine[i]+=exchanged;
				else
					wine[actIndex]+=exchanged;
				if(wine[i]>0)
					wine[i]-=exchanged;
				else
					wine[actIndex]-=exchanged;
				ans += abs(actIndex-i)*exchanged;
			}else
				i++;
			while(wine[actIndex]==0){
				actIndex++;
				if(actIndex==n)
					break;
			}
			if(i!=n-1)
				while(wine[i]==0)
					i++;

		}
		/*for(int i=0; i<n; i++){
			int j=i+1;
			while(wine[i]!=0){
				if(wine[j]!=0 && ((wine[i]>0 && wine[j]<0) || (wine[i]<0 && wine[j]>0))){
					int exchanged = processBuy(max(wine[i], wine[j]), min(wine[i], wine[j]));
					if(wine[i]<0)
						wine[i]+=exchanged;
					else if(wine[j]<0)
						wine[j]+=exchanged;
					if(wine[i]>0)
						wine[i]-=exchanged;
					else if(wine[j]>0)
						wine[j]-=exchanged;
					ans += abs(j-i)*exchanged;

				}				
				j++;
			}
		}*/
		cout << ans << endl;
		cin >> n;
	}
}
