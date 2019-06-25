#include <bits/stdc++.h>
using namespace std;

int n, h, r=0;
struct AirFlow{
    int x1;
    int x2;
};
AirFlow airFlow[200500];

// int sumAirFlow(int start, int end){
//     int r = 0;
//     for(int i=start; i<end; i++)
//         r += airFlow[i].x2-airFlow[i].x1;
//     return r;
// }

int main(){
    cin >> n >> h;
    for(int i=0; i<n; i++)
        cin >> airFlow[i].x1 >> airFlow[i].x2;
    
    int left = 0, right = 0, actHeight = h, actSumAirFlow = 0;
    while(left!=n && right!=n){
        actHeight = h - (airFlow[right].x1 - airFlow[left].x1 - actSumAirFlow);
        if(actHeight<=0){
            int deltaDistance = airFlow[right].x1 - airFlow[left].x1 - abs(actHeight);
            r = max(r, deltaDistance);
            actSumAirFlow -= airFlow[left].x2-airFlow[left].x1;
            left++;
            
        }else{
            if(right==n-1){
                int deltaDistance = airFlow[right].x1 - airFlow[left].x1 + actHeight + (airFlow[right].x2 - airFlow[right].x1);
                r = max(r, deltaDistance);

            }
            actSumAirFlow += airFlow[right].x2-airFlow[right].x1;
            right++;
            
        }
    }
    /*
    for(int i=0; i<n; i++){
        bool exceeded = false;
        int deltaDistance = 0, actHeight = h;
        for(int j=i+1; j<n; j++){
            actHeight = h-(airFlow[j].x1 - airFlow[i].x1 - sumAirFlow(i, j));
            if(actHeight<=0){
                exceeded = true;
                deltaDistance = airFlow[j].x1 - airFlow[i].x1 - abs(actHeight);
                break;
            }
        }
        if(!exceeded)
            deltaDistance = airFlow[n-1].x1 - airFlow[i].x1 + actHeight + (airFlow[n-1].x2 - airFlow[n-1].x1);
        
        r = max(r, deltaDistance);
    }
    */
    cout << r;
    
}