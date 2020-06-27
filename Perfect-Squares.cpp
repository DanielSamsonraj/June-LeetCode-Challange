class Solution {
public:
    int numSquares(int n) {
        int b = sqrt(double(n) + 0.5);
        vector<int> dp(n + 1, 1000);
        dp[0] = 0;
        for(int i = 0; i <= n; i ++){
            for(int j = 1; j <= b; j ++){
                int nxt = i + j * j;
                if(nxt > n) break;
                if(dp[nxt] > dp[i] + 1) dp[nxt] = dp[i] + 1;
            }
        }
        return dp[n];
    }
};
