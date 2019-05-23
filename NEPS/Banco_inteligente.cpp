#include <bits/stdc++.h>
#define MAX 5010
int r=0;
int s;
int div[6] = {100, 50, 20, 10, 5, 2};
int quantMoedas[6];
int dpMemo[MAX][6];

using namespace std;

void dp(int s, int moedaAtual){

}

int main(){
    cin >> s;
    for(int i=5; i>=0; i++)
        cin >> quantMoedas[i];
    dp(s, 0);
    cout << r;
}