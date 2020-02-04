#include <bits/stdc++.h>

using namespace std;

typedef struct{
    string var;
    int val;
} Variavel;

string data[110][110];
int resLinha[110];
int resCol[110];
vector<Variavel> variaveis;

bool isVariavelEqual(Variavel v){
    for(Variavel i : variaveis){
        if(!i.var.compare(v.var))
            return true;
    }
}

bool isVariavelSet(Variavel v){
    return (v.val==INT32_MAX);
}

int l, c;

int main(){
    cin >> l >> c;
    for(int i=0; i<l; i++){
        
    }
}