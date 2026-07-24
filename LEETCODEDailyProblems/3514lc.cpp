class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048; // nums[i] <= 1500 < 2048

        vector<int> values;
        vector<bool> seen(MAXX, false);

        for (int x : nums) {
            if (!seen[x]) {
                seen[x] = true;
                values.push_back(x);
            }
        }

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int k = 1; k <= 3; k++) {
            for (int x = 0; x < MAXX; x++) {
                if (!dp[k - 1][x]) continue;
                for (int v : values) {
                    dp[k][x ^ v] = true;
                }
            }
        }

        int ans = 0;
        for (bool ok : dp[3]) {
            if (ok) ans++;
        }

        return ans;
    }
};
