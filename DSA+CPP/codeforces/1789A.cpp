#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		bool ok = false;
		for(int i = 0; i < n-1; i++){
			for(int j = i + 1; j < n; j++){
				if(__gcd(arr[i],arr[j]) <= 2){
					ok = true;
					break;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
		
	}
}