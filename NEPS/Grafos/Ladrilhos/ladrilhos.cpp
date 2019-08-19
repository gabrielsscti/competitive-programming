#include <bits/stdc++.h>
#define MAX 200
using namespace std;

int mosaico[210][210];
bool isVerified[210][210];
int h, l;

bool isValidPosition(int value, int limit){
    return (value>=0 && value<limit);
}

int getLength(int x, int y){
    int length = 1;
    isVerified[x][y] = true;
    if(mosaico[x][y]==mosaico[x-1][y] && isValidPosition(x-1, h) && !isVerified[x-1][y])
        length += getLength(x-1, y);
    if(mosaico[x][y]==mosaico[x+1][y] && isValidPosition(x+1, h) && !isVerified[x+1][y] )
        length += getLength(x+1, y);
    if(mosaico[x][y]==mosaico[x][y-1] && isValidPosition(y-1, l) && !isVerified[x][y-1])
        length += getLength(x, y-1);
    if(mosaico[x][y]==mosaico[x][y+1] && isValidPosition(y+1, l) && !isVerified[x][y+1])
        length += getLength(x, y+1);
    return length;
}

int main(){
    memset(isVerified, false, sizeof(isVerified));
    cin >> h >> l;
    for(int i=0; i<h; i++)
        for(int j=0; j<l; j++)
            cin >>mosaico[i][j];
    int smallerLength = getLength(0, 0);
    for(int i=0; i<h; i++)
        for(int j=0; j<l; j++)
            if(!isVerified[i][j]){
                int temp = getLength(i, j);
                if(temp<smallerLength)
                    smallerLength = temp;
            }

    cout << smallerLength << endl;
    
    return 0;
}