//https://neps.academy/lesson/180
#include <bits/stdc++.h>
#define MAX 60010
#define INF 0x3f3f3f3f
using namespace std;

int n;
int pregos[MAX];

int countInv(int *vIni, int *vFim){
    int r = 0;
    if(vIni+1==vFim)
        return 0;
    int vSize = vFim-vIni;
    int half1 = vSize/2;
    int half2 = vSize%2==0 ? vSize/2 : (vSize/2)+1;
    int *v1 = (int*)malloc(sizeof(int)*(half1+1));
    int *v2 = (int*)malloc(sizeof(int)*(half2+1));
    for(int i=0; i<half1; i++)
        v1[i] = vIni[i];
    for(int i=half1, j=0; i<vSize; i++, j++)
        v2[j] = vIni[i];
    r+=countInv(v1, v1+half1);
    r+=countInv(v2, v2+half2);
    v1[half1] = INT32_MAX;
    v2[half2] = INT32_MAX;
    int ini1=0, ini2=0;

    for(int i=0; i<vSize; i++){
        if(v1[ini1]<v2[ini2])
            vIni[i] = v1[ini1++];
        else{
            vIni[i] = v2[ini2++];
            r+=half1-ini1;
        }
        
    }
    return r;
    

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> pregos[i];
    cout << countInv(pregos, pregos+n) << endl;
}