class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        
        int result = 1;
        a %= MOD;

        for (int digit : b) {
            result = modPow(result, 10) * modPow(a, digit) % MOD;
        }

        return result;
    }

    int modPow(int a, int b) {
        int result = 1;
        
        while (b > 0) {
            if (b & 1)
                result = result * a % 1337;
            
            a = a * a % 1337;
            b >>= 1;
        }
        
        return result;
    }
};