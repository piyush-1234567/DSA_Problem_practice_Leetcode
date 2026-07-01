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
        int maxi = *max_element(arr.begin(),arr.end());
        vector<int> b,c;
        for(int i = 0; i < n; i++){
            if(arr[i] == maxi){
                c.push_back(arr[i]);
            }else{
                b.push_back(arr[i]);
            }

        }
        if(b.empty() || c.empty()){
            cout << "-1" << endl;
            continue;
        }
        cout << b.size() << " " << c.size() << endl;
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < c.size(); i++){
            cout << c[i] << " ";
        }
        cout << endl;


    }
}