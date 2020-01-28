#include <bits/stdc++.h>
#define HORARIO 1
#define ANTIHORARIO 2
#define DAMA 12
#define VALETE 11

using namespace std;

typedef struct{
    int valorTotal;
    int valor;
    char naipe;
} Carta;

typedef struct{
    vector<Carta> mao;
}Jogador;

int p, m, n, vencedor;
bool gotDiscarded=true;
vector<Carta> saque, descarte;
vector<Jogador> jogador;

void resetVectors(){
    saque.clear();
    descarte.clear();
    jogador.clear();
}

void debugJogador(){
    for(int i=0; i<jogador.size(); i++){
        cout << "Jogador " << i+1 << ":" << endl;
        Jogador tempJ = jogador.at(i);
        for(int j=0; j<tempJ.mao.size(); j++){
            Carta tempC = tempJ.mao.at(j);
            cout << tempC.valorTotal << "-" << tempC.valor << "-" << tempC.naipe << endl;
        }
    }
}

void debugDescarte(){
    cout << "Descarte: " << endl;
    for(auto it=descarte.begin(); it!=descarte.end(); it++){
        cout << (*it).valorTotal << "-" << (*it).valor << "-" << (*it).naipe << endl;
    }
}


int getNaipeValue(char naipe){
    if(naipe=='C')
        return 1;
    if(naipe=='D')
        return 2;
    if(naipe=='H')
        return 3;
    if(naipe=='S')
        return 4;
}


bool isFinished(){
    for(auto it=jogador.begin(); it!=jogador.end(); it++){
        if((*it).mao.size()==0){
            vencedor = (it-jogador.begin())+1;
            return true;
        }
    }
    return false;
}

Carta pegaSaque(){
    Carta c = saque.back();
    saque.pop_back();
    return c;
}

void insereCarta(int j, Carta c){
    jogador.at(j).mao.push_back(c);

}

Carta getTopoSaque(){
    return saque.back();
}

Carta getTopoDescarte(){
    return descarte.back();
}

void descartaCarta(Carta c){
    gotDiscarded=true;
    descarte.push_back(c);
}

void debugSaque(){
    cout << "Saque:" << endl;
    cout << (*(saque.end()-1)).valorTotal << "-" << (*(saque.end()-1)).valor << "-" << (*(saque.end()-1)).naipe << endl;
    cout << (*saque.end()).valorTotal << "-" << (*saque.end()).valor << "-" << (*saque.end()).naipe << endl;

}

void debugCarta(Carta c){
    printf("%d-%d-%c\n", c.valorTotal, c.valor, c.naipe);
}

bool descartaMaiorCarta(int j, Carta alvo){
    vector<Carta> candidatas;
    Carta temp;
    int maior = -1;
    for(auto it=jogador.at(j).mao.begin(); it!=jogador.at(j).mao.end(); it++){
        if((*it).valor==alvo.valor || (*it).naipe==alvo.naipe){
            candidatas.push_back(*it);
        }
    }
    for(auto it=candidatas.begin(); it!=candidatas.end(); it++)
        if((*it).valorTotal>maior){
            maior = (*it).valorTotal;
            temp = (*it);
        }
    for(auto it=jogador.at(j).mao.begin(); it!=jogador.at(j).mao.end(); it++){
        
        if((*it).valor==temp.valor && (*it).naipe==temp.naipe){
            descartaCarta(*it);
            jogador.at(j).mao.erase(it);
            return true;
        }
    }
    return false;

}


bool isFimVez(int vez, int direction){
    if(vez==0 && direction==ANTIHORARIO)
        return true;
    if(vez==p-1 && direction==HORARIO)
        return true;

    return false;
}

int getDirection(int direction){
    if(direction==ANTIHORARIO)
        return HORARIO;
    return ANTIHORARIO;
}

int main(){
    cin >> p >> m >> n;
    while(p!=0 || m!=0 || n!=0){
        for(int i=0; i<n; i++){
            int valor;
            char naipe;
            cin >> valor >> naipe;
            int valorTotal = ((valor-1)*4)+getNaipeValue(naipe);
            saque.push_back({valorTotal, valor, naipe});
        }
        reverse(saque.begin(), saque.end());
        for(int i=0; i<p; i++){
            Jogador tempJ;
            jogador.push_back(tempJ);
            for(int j=0; j<m; j++){
                Carta c = saque.back();
                jogador.back().mao.push_back(c);
                saque.pop_back();
            }
        }

        int direction = HORARIO;
        int turn=0;
        gotDiscarded=true;
        descartaCarta(pegaSaque());
        while(!isFinished()){
            bool perdeuVez = false;
            auto jogadorAtual = jogador.begin()+turn;
            Carta topoDescarte = getTopoDescarte();
            if(gotDiscarded){
                if(topoDescarte.valor==DAMA){
                    direction = getDirection(direction);
                    
                }
                else if(topoDescarte.valor==7){
                    Carta c1 = pegaSaque();
                    Carta c2 = pegaSaque();
                    insereCarta(turn, c1);
                    insereCarta(turn, c2);
                    perdeuVez = true;
                }
                else if(topoDescarte.valor==1){
                    Carta c = pegaSaque();
                    insereCarta(turn, c);
                    perdeuVez = true;
                }
                else if(topoDescarte.valor==VALETE){
                    perdeuVez = true;
                }
                gotDiscarded = false;
            }
            if(!perdeuVez){
                if(!descartaMaiorCarta(turn, getTopoDescarte())){
                    insereCarta(turn, pegaSaque());
                    descartaMaiorCarta(turn, getTopoDescarte());
                }
                if(getTopoDescarte().valor==DAMA && gotDiscarded){
                    direction = getDirection(direction);
                    gotDiscarded = false;
                }
            }
            if(isFimVez(turn, direction)){
                if(direction==HORARIO)
                    turn = 0;
                else if(direction==ANTIHORARIO)
                    turn = p-1;
            }else{
                if(direction==HORARIO)
                    turn++;
                else
                    turn--;
            }
        }
        resetVectors();
        cout << vencedor << endl;
        
        cin >> p >> m >> n;
    }
}