#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int>& nums) {
    unordered_map<long long, int> freq;

    for (int x : nums)
        freq[x]++;

    int ans = 1;

    // Handle the special case for 1
    if (freq.count(1)) {
        if (freq[1] % 2 == 0)
            ans = max(ans, freq[1] - 1);
        else
            ans = max(ans, freq[1]);
    }

    for (auto &[num, cnt] : freq) {
        if (num == 1) continue;

        long long cur = num;
        int len = 0;

        while (freq.count(cur) && freq[cur] >= 2) {
            len += 2;

            // Prevent overflow
            if (cur > 1000000000LL)
                break;

            cur = cur * cur;
        }

        if (freq.count(cur))
            len++;
        else
            len--;

        ans = max(ans, len);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maximumLength(nums) << endl;

    return 0;
}