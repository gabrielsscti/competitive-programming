#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, n;
    cin >> l >> n;
    for(int i=0; i<n; i++){
        int w, h;
        cin >> w >> h;
        if(w<l || h<l)
            cout << "UPLOAD ANOTHER" << endl;
        else{
            if(w==h)
                cout << "ACCEPTED" << endl;
            else
                cout << "CROP IT" << endl;
        }
    }
}