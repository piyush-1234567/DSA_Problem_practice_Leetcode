class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int prod = 1, x = n;
            while (x) { prod *= x % 10; x /= 10; }
            if (prod % t == 0) return n;
            n++;
        }
    }
};
