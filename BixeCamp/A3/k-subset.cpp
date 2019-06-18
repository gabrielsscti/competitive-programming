#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int n, k, r=0;
struct Set{
    int number;
    bool isTaken;
};
Set a[MAX];
int hasTarget(int ini, int fim, int target){
    int mid = (ini+fim)/2;
    while(ini<=fim){
        if(a[mid].number==target)
            return mid;
        else if(a[mid].number>target)
            fim = mid-1;
        else
            ini = mid+1;
        mid = (ini+fim)/2;
    }
    return -1;
}

// void debug(){
//     for(int i=0; i<n; i++)
//         printf("%d\t", a[i].number);
//     cout << endl;
//     for(int i=0; i<n; i++)
//         printf("%d\t", a[i].isTaken);
//     cout << endl;
// }

bool comparaValores(Set a, Set b){
    return a.number<b.number;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i].number);
        a[i].isTaken = false;
    }
    sort(a, a+n, comparaValores);
    for(int i=n-1; i>=r; i--){
        int count = 0;
        
        for(int i2=i; i2>=0; i2--){
            int target;
            if(a[i2].isTaken)
                target = -1;
            else
                target = hasTarget(0, i2, a[i2].number/k);
            if(target!=-1)
                a[target].isTaken = true;
            

        }
        for(int i2=0; i2<=i; i2++){
            if(!a[i2].isTaken)
                count++;
            a[i2].isTaken = false;
        }
        r = max(r, count);
    }
    
    cout << r;
}