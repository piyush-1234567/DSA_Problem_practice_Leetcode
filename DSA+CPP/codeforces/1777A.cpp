#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0 ; i < n; i++){
			cin >> arr[i];
		}
		int len = 1;
		int ans = 0;
		for(int i = 1; i < n; i++){
			if(arr[i]%2 == arr[i-1]%2){
				len++;
			}else{
				ans += (len - 1);
				len = 1;
			}
		}
		ans += (len-1);

		cout << ans << endl;
	}
}