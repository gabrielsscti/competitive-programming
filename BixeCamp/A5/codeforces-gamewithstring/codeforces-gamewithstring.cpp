#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	bool isFirstPlayerTurn = true;
	cin >> s;
	int actPos = 0;
	while(actPos!=s.size()){
		if(s[actPos]==s[actPos+1]){
			s.erase(actPos, 1);
			s.erase(actPos, 1);
			isFirstPlayerTurn = !isFirstPlayerTurn;
			if(actPos!=0)
				actPos--;
		}else
			actPos++;

	
	}
	cout << (isFirstPlayerTurn ? "No" : "Yes") << endl;
	return 0;
}
