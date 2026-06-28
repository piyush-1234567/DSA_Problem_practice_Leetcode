#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int maxEl = -1;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                arr[0] = 1;
            }
            else if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }

            maxEl = max(maxEl, arr[i]);
        }

        return maxEl;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int ans = obj.maximumElementAfterDecrementingAndRearranging(arr);

    cout << "\nMaximum Element: " << ans << endl;

    cout << "Modified Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}