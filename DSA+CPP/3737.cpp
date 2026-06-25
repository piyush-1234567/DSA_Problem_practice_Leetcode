class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int ct = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == target) ct++;
                int len = j - i + 1;
                if(ct > len/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};
