#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
	public:
		int numOfStrings(vector<string>&patterns , string word){
			int count = 0;
			for(string &s: patterns){
				if(word.find(s) != string::npos){
					count++;
				}
			}
			return count;
		} 
};
int main(){
	vector<string> patterns = {"a", "abc", "bc", "d"};
	string word = "abc";
	Solution obj;
	cout << obj.numOfStrings(patterns,word) << endl;
}