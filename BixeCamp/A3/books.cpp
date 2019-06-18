#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

int n, t, books[MAX];
int r=0, sum=0;

int main(){
    scanf("%d%d", &n, &t);
    for(int i=0; i<n; i++)
        scanf("%d", &books[i]);
    int lastPos=0, temp=0;
    for(int i=0; i<n; i++){
        int timeLeft = t-sum;
        for(int i2=lastPos; i2<n; i2++){
            if(timeLeft>=books[i2]){
                sum += books[i2];
                timeLeft -= books[i2];
                temp++;
                lastPos = i2+1;
            }
            else
                break;
        }
        sum -= books[i];
        
        r = max(temp, r);
        temp=temp-1;

    }
    printf("%d", r);
    return 0;
}