#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 9, A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) { 
        sum += A[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0; 
    } 
    printf("%d\n", ans);
}