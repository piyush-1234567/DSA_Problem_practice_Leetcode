#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int total = 0;
        for (int i = 0; i < 10; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    total += min({i, j, 9 - i, 9 - j}) + 1;
                }
            }
        }
        cout << total << "\n";
    }
    return 0;
}