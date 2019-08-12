#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int seat = n%12;
        if(seat==0)
            seat = 12;
        int facingSeat;
        if(seat<=6)
            facingSeat=13-seat;
        else
            facingSeat = 13%seat;
        cout << (n<=12 ? facingSeat : (seat==12 ? (facingSeat+(12*((n-1)/12))) : (facingSeat+(12*(n/12))))) << " ";
        if(seat==6 || seat==7 || seat==1 || seat==12)
            cout << "WS" << endl;
        else if(seat==5 || seat==8 || seat==2 || seat == 11)
            cout << "MS" << endl;
        else if(seat==4 || seat==9 || seat==3 || seat==10)
            cout << "AS" << endl;
    }
}