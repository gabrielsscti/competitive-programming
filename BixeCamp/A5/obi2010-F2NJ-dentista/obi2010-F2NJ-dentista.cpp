#include <bits/stdc++.h>
using namespace std;

struct Horario{
	int ini, fim;
};

bool compareHorario(Horario a, Horario b){
	return (a.fim < b.fim);
}

int n;
Horario horarios[10100];

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> horarios[i].ini >> horarios[i].fim;
	sort(horarios, horarios+n, compareHorario);
	int actEnd = horarios[0].fim;
	int ans = 1;
	for(int i=1; i<n; i++){
		if(actEnd<=horarios[i].ini){
			actEnd = horarios[i].fim;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
