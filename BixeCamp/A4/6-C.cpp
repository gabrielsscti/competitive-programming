#include <bits/stdc++.h>
using namespace std;

int n;
int t[100000];

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> t[i];
    int left=0, right = n-1, timeLeft=t[left], timeRight=t[right], ansRight=0, ansLeft=0;

    if(n==1)
        ansLeft=1, ansRight=0;

    while(left!=right){
        int timePassed = min(timeLeft, timeRight);
        timeLeft-=timePassed;
        timeRight-=timePassed;
        if(timeLeft<=0){
            timeLeft = t[++left];
            ansLeft++;
            if(left==right){
                ansRight++;
                break;
            }
        }
        if(timeRight<=0){
            timeRight = t[--right];
            ansRight++;
            
        }
        if(left==right){
            ansLeft++;
            break;
        }

    }
    cout << ansLeft << " " << ansRight;
}