#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int longest = 1, curr = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] <= k) {
                curr++;
            } else {
                longest = max(longest, curr);
                curr = 1;
            }
        }

        longest = max(longest, curr);

        cout << n - longest << "\n";
    }

    return 0;
}
