class Solution {
public:
    vector<int> res;
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 1; i < nums.size(); i++){
            int n = nums[i] - nums[i-1];
            if(n > 1){
                sum = nums[i-1];
                for(int i = 1; i < n; i++){
                    sum++;
                    res.push_back(sum);
                    
                    
                }
            }
        }
        return res;
    }
};
/*
nums = [1.4.2.5]
sort.nums = [1,2,4,5]
nums[1] - nums[0] = 2 - 1 = 1
nums[2] - nums[1] = 4 - 2 = 2 push back
nums[3] - nums[2] = 5 - 4 = 1 
if difference is greater than 1 add it to the result array
*/
