#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int M = *max_element(a.begin(), a.end());

        vector<int> b, c;
        for (int x : a) {
            if (x == M) c.push_back(x);
            else b.push_back(x);
        }

        if (b.empty() || c.empty()) {
            cout << -1 << "\n";
            continue;
        }

        cout << b.size() << " " << c.size() << "\n";
        for (int x : b) cout << x << " ";
        cout << "\n";
        for (int x : c) cout << x << " ";
        cout << "\n";
    }
    return 0;
}