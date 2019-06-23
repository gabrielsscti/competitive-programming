#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int n, k, r=0;
struct Set{
    int number;
    bool isTaken;
};
Set a[MAX];
int binarySearch(int ini, int fim, long long int target){
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
    for(int i=0; i<n; i++)
        if(!a[i].isTaken){
            int target = binarySearch(0, n-1, k*1LL*a[i].number);
            r++;
            if(target!=-1)
                a[target].isTaken = true;
            
        }
    
    
    cout << r;
}