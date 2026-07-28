class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        string half, mid;
        for (int i = 0; i < 26; i++) {
            half += string(cnt[i] / 2, 'a' + i);
            if (cnt[i] % 2) mid = string(1, 'a' + i);
        }
        return half + mid + string(half.rbegin(), half.rend());
    }
};
