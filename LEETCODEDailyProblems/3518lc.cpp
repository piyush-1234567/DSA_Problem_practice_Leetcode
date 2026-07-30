class Solution {
public:
    typedef long long ll;
    const ll CAP = 2000000000000LL; // safely above max possible k

    ll nCk(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        if (k > n - k) k = n - k;
        ll res = 1;
        for (ll i = 1; i <= k; i++) {
            // use __int128 to avoid overflow during the multiply
            __int128 tmp = (__int128)res * (n - k + i) / i;
            res = (tmp > CAP) ? (CAP + 1) : (ll)tmp;
            if (res > CAP) return CAP + 1;
        }
        return res;
    }

    ll countWays(vector<int>& half) {
        ll remaining = 0, ways = 1;
        for (int c = 0; c < 26; c++) {
            if (half[c] == 0) continue;
            remaining += half[c];
            ll factor = nCk(remaining, half[c]);
            // guard the ways *= factor multiply too
            __int128 tmp = (__int128)ways * factor;
            ways = (tmp > CAP) ? (CAP + 1) : (ll)tmp;
            if (ways > CAP) return CAP + 1;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        ll kk = k;
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;
        for (int c = 0; c < 26; c++) {
            half[c] = cnt[c] / 2;
            if (cnt[c] % 2) mid = 'a' + c;
        }

        int m = n / 2;
        vector<int> check = half;
        if (countWays(check) < kk) return "";

        string left;
        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;
                half[c]--;
                ll ways = countWays(half);
                if (ways >= kk) {
                    left.push_back('a' + c);
                    break;
                } else {
                    kk -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return mid ? left + mid + right : left + right;
    }
};