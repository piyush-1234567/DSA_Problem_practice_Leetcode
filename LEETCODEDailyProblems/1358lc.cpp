#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA = -1, lastB = -1, lastC = -1;
        long long count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                lastA = i;
            } else if (s[i] == 'b') {
                lastB = i;
            } else {
                lastC = i;
            }
            if (lastA != -1 && lastB != -1 && lastC != -1) {
                int m = min({lastA, lastB, lastC});
                count += (m + 1);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabc";
    cout << "Input: " << s1 << " -> Output: " << sol.numberOfSubstrings(s1) << endl;

    string s2 = "aaacb";
    cout << "Input: " << s2 << " -> Output: " << sol.numberOfSubstrings(s2) << endl;

    string s3 = "abc";
    cout << "Input: " << s3 << " -> Output: " << sol.numberOfSubstrings(s3) << endl;

    return 0;
}