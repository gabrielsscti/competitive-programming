#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli t;

lli getValue(double x, lli d){
    return (lli)ceil(x+((d)/(x+1)));
}

bool solve(lli n, lli d){
    lli delta = 1+2*n+pow(n, 2)-4*d;
    if(delta<0)
        return false;
    double x1 = (-1+n+sqrt(delta))/2;
    double x2 = (-1+n+sqrt(delta))/2;
    if(x1>=0 && x2>=0){
        lli temp = min(x1, x2);
        if(getValue(temp, d)<=n)
            return true;
        return false;
    }else if(x1>=0){
        if(getValue(x1, d)<=n)
            return true;
        return false;
    }else if(x2>=0){
        if(getValue(x2, d)<=n)
            return true;
    }
    return false;
}

int main(){
    cin >> t;
    while(t--){
        lli n, d;
        cin >> n >> d;
        if(solve(n, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    return 0;
}