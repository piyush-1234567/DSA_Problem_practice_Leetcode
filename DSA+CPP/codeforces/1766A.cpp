#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int cnt = 0;
		for(int i = 1 ; i <= n; i *= 10){
			for(int d = 1; d <= 9; d++){
				if(d * i <= n){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}


}