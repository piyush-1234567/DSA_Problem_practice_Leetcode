class Solution {
public:
    long long uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        int bits = 0;
        int temp = n;
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }
        return 1LL << bits;
    }
};