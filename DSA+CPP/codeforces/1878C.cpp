#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k ,x;
		cin >> n >> k >> x;
		long long maxSum = k * (n + n - k + 1)/2;
		long long smalSum = k * (k + 1)/2;

		if(x <= maxSum && x >= smalSum){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}