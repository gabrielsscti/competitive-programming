#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

struct Operation{
	int l, r, d;
};

int n, m, k;
int a[MAX+10];
long long int sum[MAX+10];
Operation ops[MAX+10];


int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum[i] = 0;
	}
	for(int i=0; i<m; i++){
		cin >> ops[i].l >> ops[i].r >> ops[i].d;
		ops[i].l--, ops[i].r--;
		cout << ops[i].l << " " << ops[i].r << endl;
		for(int j=ops[i].l; j<=ops[i].r; j++)
			sum[j] += ops[i].d;

	}
	for(int i=0; i<n; i++)
		cout << sum[i] << " ";

}
