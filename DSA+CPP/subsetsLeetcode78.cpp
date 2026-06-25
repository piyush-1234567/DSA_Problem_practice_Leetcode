#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, int index) {
        if(index >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        // Include the current element
        curr.push_back(nums[index]);
        solve(nums, curr, index + 1);

        // Exclude the current element
        curr.pop_back();
        solve(nums, curr, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, curr, 0);
        return ans;
    }
};

// Helper function to print 2D vector
void printSubsets(const vector<vector<int>>& subsets) {
    for(const auto& subset : subsets) {
        cout << "[";
        for(size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if(i != subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3}; // Example input

    vector<vector<int>> result = solution.subsets(nums);

    cout << "All subsets:\n";
    printSubsets(result);

    return 0;
}
