#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int height[100100];

struct Pair{
	int value;
	int index;
};

int getSmallerIndex(int start, int end){
	int smaller = height[start], smallerIndex = start;
	
	for(int i=start; i<=end; i++)
		if(smaller>height[i]){
			smaller = height[i];
			smallerIndex = i;
		}
	return smallerIndex;
}

int getLargerIndex(int start, int end){
	int larger = height[start], largerIndex = start;
	for(int i=start; i<=end; i++)
		if(larger<height[i]){
			larger = height[i];
			largerIndex = i;
		}
	return largerIndex;
}

void debug(Pair smallPair, Pair largePair){
	cout << "Smaller Value: " << smallPair.value << "-" << smallPair.index << endl;
	cout << "Bigger Value: " << largePair.value << "-" << largePair.index << endl;
}


int solve(){
	int left=0, right=k+1, answer=0;
	if(right>=n)
		right = n-1;
	Pair smaller, larger;
	{
		int smallerIndex = getSmallerIndex(left, right);
		int largerIndex = getLargerIndex(left, right);
		smaller.value=height[smallerIndex], smaller.index=smallerIndex;
		larger.value=height[largerIndex], larger.index=largerIndex;
	}

	while(right<n){
		if(smaller.index<left){
			int newSmallerIndex = getSmallerIndex(left, right);
			smaller.value = height[newSmallerIndex], smaller.index = newSmallerIndex;
		}
		if(larger.index<left){
			int newLargerIndex = getLargerIndex(left, right);
			larger.value = height[newLargerIndex], larger.index = newLargerIndex;
		}
		answer = max(answer, larger.value-smaller.value);
		left++, right++;
		if(height[right]<smaller.value)
			smaller.value = height[right], smaller.index = right;
		if(height[right]>larger.value)
			larger.value = height[right], larger.index = right;


	}
	return answer;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0; i<n; i++)
			cin >> height[i];
		cout << solve() << endl;
	}


}
