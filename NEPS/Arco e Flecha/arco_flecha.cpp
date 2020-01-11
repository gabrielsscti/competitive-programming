#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long int lli;
int n;
lli distances[MAX];

lli getNorma(int x, int y){
    return (lli)x*(lli)x + (lli)y*(lli)y;
}

lli solve(lli *vIni, lli *vFim){
    if(vIni+1==vFim)
        return 0;

    lli r = 0;
    int vSize = vFim-vIni;
    int half1 = vSize/2;
    int half2 = vSize%2==0 ? vSize/2 : (vSize/2)+1;
    lli *v1 = (lli*)malloc(sizeof(lli)*(half1+1));
    lli *v2 = (lli*)malloc(sizeof(lli)*(half2+1));

    for(int i=0; i<half1; i++)
        v1[i] = vIni[i];
    for(int i=half1, j=0; i<vSize; i++, j++)
        v2[j] = vIni[i];
    
    r+=solve(v1, v1+half1);
    r+=solve(v2, v2+half2);
    v1[half1] = INT64_MIN;
    v2[half2] = INT64_MIN;
    int ini1=0, ini2=0;
    //8
    for(int i=0; i<vSize; i++){
        if(v1[ini1]>v2[ini2])
            vIni[i] = v1[ini1++];
        else{
            r+=half1-ini1;
            vIni[i] = v2[ini2++];
        }
    }
    return r;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        distances[i] = getNorma(x, y);
    }
    cout << solve(distances, distances+n) << endl;

}