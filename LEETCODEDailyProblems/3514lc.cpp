#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {6,7,8,9};
    vector<int> middle;
    for(int i = 0;i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            int x = arr[i] ^ arr[j];
            middle.push_back(x);
        }   

    }
    unordered_set<int> ans;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < middle.size(); j++){
            int y = arr[i] ^ middle[j];
            ans.insert(y);
        }
    }
   
    cout << ans.size();
}