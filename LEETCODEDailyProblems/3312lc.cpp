class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxV = *max_element(nums.begin(), nums.end());

        // cnt[v] = how many times v appears in nums
        vector<int> cnt(maxV + 1, 0);
        for (int x : nums) cnt[x]++;

        // multiple[d] = count of numbers in nums that are multiples of d
        vector<long long> multiple(maxV + 1, 0);
        for (int d = 1; d <= maxV; d++)
            for (int m = d; m <= maxV; m += d)
                multiple[d] += cnt[m];

        // pairs[d] = number of pairs (i,j) where both nums[i], nums[j] are multiples of d
        vector<long long> exact(maxV + 1, 0);
        for (int d = maxV; d >= 1; d--) {
            long long total = multiple[d] * (multiple[d] - 1) / 2;
            for (int m = 2 * d; m <= maxV; m += d)
                total -= exact[m];
            exact[d] = total; // pairs whose gcd is EXACTLY d
        }

        // prefix[d] = number of pairs with gcd <= d
        vector<long long> prefix(maxV + 1, 0);
        for (int d = 1; d <= maxV; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        // answer each query with binary search on prefix
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // find smallest d such that prefix[d] > q
            int lo = 1, hi = maxV, res = maxV;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] > q) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};