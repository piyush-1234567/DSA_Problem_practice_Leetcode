#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long a,b,c,d;
		cin >> a >> b >> c >> d;
		int k = d - b;
		if(k < 0){
			cout << -1 << endl;
			continue;
		} 
		int m = k - (c - a);
		if(m < 0){
			cout << -1 << endl;
			continue;
		}
		cout << k + m << endl;
	}
}