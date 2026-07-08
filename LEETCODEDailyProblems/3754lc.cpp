class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long number = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit;
            if(digit != 0){
                number = number * 10 + digit;
            }
            n /= 10;
        }
        long long ans = 0;
        while(number > 0){
            ans = ans * 10 + number % 10;
            number /= 10;
        }
        return ans * sum ;
    }
};