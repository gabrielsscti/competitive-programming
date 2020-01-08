#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int n;
int seq[MAX+10];

void mergeSort(int *vInicio, int *vFim){
    int tamVetor = vFim-vInicio;
    int half = tamVetor/2;
    int addingFactor = (tamVetor%2==0 ? 0 : 1);
    if(vInicio+1==vFim)
        return;
    
    int *v1 = (int*)malloc(sizeof(int)*half);
    int *v2 = (int*)malloc(sizeof(int)*half+addingFactor);

    for(int i=0; i<half; i++)
        v1[i] = vInicio[i];
    for(int i=half, j=0; i<tamVetor; i++, j++)
        v2[j] = vInicio[i];

    mergeSort(v1, v1 + half);
    mergeSort(v2, v2 + half + addingFactor);
    
    int ini1=0, ini2=0;
    for(int i=0; i<tamVetor; i++){
        if(ini1==half)
            vInicio[i] = v2[ini2++];
        else if(ini2==half+addingFactor)
            vInicio[i] = v1[ini1++];
        else{
            if(v1[ini1]<v2[ini2])
                vInicio[i] = v1[ini1++];
            else
                vInicio[i] = v2[ini2++];
        }
    }

    return;

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> seq[i];
    mergeSort(seq, seq+n);
    for(int i=n-1; i>=0; i--)
        cout << seq[i] << " ";
    

    
}