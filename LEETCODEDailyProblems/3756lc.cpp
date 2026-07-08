class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        vector<long long> digitSum(n+1,0);
        vector<long long> cntNZ(n+1,0);
        vector<long long> xPrefix(n+1,0);
        vector<long long> pow10(n+1,1);
        for(int i = 0; i < n; i++){
            int d = s[i] - '0';
            digitSum[i+1] = digitSum[i] + d;
            cntNZ[i+1] = cntNZ[i] + (d != 0);
            xPrefix[i+1] = (d!=0) ? (xPrefix[i] * 10 + d) % MOD : xPrefix[i];
            pow10[i+1] = (pow10[i] * 10) % MOD; 
        }
        vector<int> ans;
        for(auto &q: queries){
            int l = q[0] , r = q[1];
            long long sum = (digitSum[r+1] - digitSum[l]) % MOD;
            long long shift = cntNZ[r+1] - cntNZ[l];
            long long x = ((xPrefix[r+1] - xPrefix[l] * pow10[shift])%MOD + MOD)%MOD;
            ans.push_back((int)((x * sum)%MOD));
        }
        return ans;
    }
};