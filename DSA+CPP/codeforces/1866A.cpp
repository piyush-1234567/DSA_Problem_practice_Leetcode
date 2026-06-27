#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; 
	cin >> n;
	vector<int> arr(n);
	int mini = INT_MAX;

	for(int i = 0; i < n; i++){
		int ele;
		cin >> ele;
		arr[i] = ele;
		mini = min(abs(arr[i]), mini);
	}
	cout << mini;

}