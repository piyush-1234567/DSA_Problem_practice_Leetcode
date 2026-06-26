class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> positiveStack;
        int positiveSize=0;
        vector<int> negativeStack;
        long long ans=0;
        int zeros=0;
        for(int n:nums){
            if(n==target){
                positiveStack.push_back(zeros);
                positiveSize+=zeros;
                if(negativeStack.empty()){
                    zeros=0;
                }else{
                    zeros=negativeStack.back();
                    negativeStack.pop_back();
                }
                positiveSize++;
                positiveStack.back()++;
            }else{
                negativeStack.push_back(zeros);
                if(positiveStack.empty()){
                    zeros=0;
                }else{
                    zeros=positiveStack.back();
                    positiveSize-=positiveStack.back();
                    positiveStack.pop_back();
                }
                negativeStack.back()++;
            }
            ans+=positiveSize;
        }
        return ans;
    }
};