#include <stdlib.h>
#include <stdio.h>
 
typedef struct{
  int valor;
  char nipe;
 
}carta;
 
int parada(carta *cartas, int qtd_cartas){    //funçao para conferir sempre se o jogador atual possui cartas para jogar fora
    int i;
    for(i = 0; i < qtd_cartas; i++){
 
        if(cartas[i].valor > 0) //nao precisaria do maior q 0.
            return 1;
    }
       
    return 0;
}
 
int selec_maior(carta *cartas, int qtd_cartas, carta descarte){
    int i, maior, chave_maior;
 
   
   
    chave_maior = -1;
    maior = 0;
    for(i = 0; i < qtd_cartas; i++){
        if(maior < cartas[i].valor*19 + (cartas[i].nipe - 64) && (descarte.valor == cartas[i].valor || descarte.nipe == cartas[i].nipe) ){
 
            maior = cartas[i].valor*19 + (cartas[i].nipe - 64);
            chave_maior = i;
        }        
    }
 
    return chave_maior;
}
 
int main(){
 
    int m, n, p, i, j, qtd_carta_mao[10], sentido, bara_atual, joga_atual, aux;
    carta jogadores[10][300], baralho[300], descarte;
   
    scanf("%d %d %d", &m, &n, &p);
 
    for( i = 0; i < m; i++){ //qtd jogadores
       qtd_carta_mao[i] = n;      
       for(j = 0; j < n; j++){  // qtd cartas d cada jogadr
                       
            scanf("%d %c", &jogadores[i][j].valor, &jogadores[i][j].nipe );
           
        }    
    }
                   
    scanf("%d %c", &descarte.valor, &descarte.nipe);
 
    for( i = 0; i < p-(m*n)-1; i++){ //lendo baralho    
        scanf("%d %c", &baralho[i].valor, &baralho[i].nipe);  
    }
   
    joga_atual = -1;    
    sentido = 1;   // direçao do jogo 1 horario -1 antihorario    
    bara_atual = 0;            
 
    do{
       
        if(joga_atual+sentido == -1){           // verificando os limites extremos do vetor
            joga_atual = m-1;
        }else if(joga_atual+sentido == m){
            joga_atual = 0;    
        }else
            joga_atual += sentido;
 
        if( descarte.valor == 12 ){
            if (sentido == 1)
                sentido = -1;
            else
                sentido = 1;
        }else if( descarte.valor == 7 ){
               
               jogadores[joga_atual][qtd_carta_mao[joga_atual]++] = baralho[bara_atual++];
               jogadores[joga_atual][qtd_carta_mao[joga_atual]++] = baralho[bara_atual++];
 
            }else if( descarte.valor == 1 ){
 
               jogadores[joga_atual][qtd_carta_mao[joga_atual]++] = baralho[bara_atual++];
 
            }else if( descarte.valor != 11){ // ou seja, descarta carta
                   
                           if( ( aux = selec_maior(jogadores[joga_atual], qtd_carta_mao[i], descarte) ) == -1){
                                if( descarte.valor != baralho[bara_atual].valor && descarte.nipe != baralho[bara_atual].nipe )
                                    jogadores[joga_atual][qtd_carta_mao[joga_atual]++] = baralho[bara_atual];
                                bara_atual++;
     // add carta na mao
                           }else{
                           
                                jogadores[joga_atual][aux].valor = 0;  
                                jogadores[joga_atual][aux].nipe = 'a';                                
                           }
                                   
            }
             
    }while(parada(jogadores[joga_atual],qtd_carta_mao[joga_atual]));  
 
    printf("Jogador atual : %d \n", joga_atual+1);
 
    return 0;
}
