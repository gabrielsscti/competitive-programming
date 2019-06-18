#include <bits/stdc++.h>
using namespace std;
int l, n;
int a[1010];
double r = 0;

int main(){
    cin >> n >> l;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++){
        if(i==0){
            r = (double)a[i];
            if(i==n-1)
                r = max((double)l-a[i], r);
        }
        else if(i==n-1)
            r = max((double)(a[i]-a[i-1])/2, max((double)(l-a[i]), r));
        else
            r = max((double)(a[i]-a[i-1])/2, r);

    }
    cout.precision(10);
    cout <<fixed<< r  << endl;
}