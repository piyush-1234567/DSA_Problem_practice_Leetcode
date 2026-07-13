#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        long long k = d - b;          // number of up-right moves
        if (k < 0) {
            printf("-1\n");
            continue;
        }

        long long m = k - (c - a);    // number of left moves
        if (m < 0) {
            printf("-1\n");
            continue;
        }

        printf("%lld\n", k + m);
    }
    return 0;
}