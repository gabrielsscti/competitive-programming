#include <bits/stdc++.h>
using namespace std;
int n, k, l, c, d, p, nl, np;
int totalMililiters, totalSlicesOfLime;
int toastsByMililiters, toastsBySliceOfLime, toastsByGramsOfSalt;
int main(){
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    totalMililiters = k*l;
    totalSlicesOfLime = c*d;
    toastsByMililiters = totalMililiters/nl;
    toastsBySliceOfLime = totalSlicesOfLime;
    toastsByGramsOfSalt = p/np;
    cout << min(toastsByMililiters, min(toastsBySliceOfLime, toastsByGramsOfSalt))/n << endl;

}