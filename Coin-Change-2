class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(!amount) return 1;
        vector<int> dp(amount+1,0);
        for(auto it:coins) {
            if(it<=amount) dp[it] += 1;
            for(int i=it+1;i<=amount;i++) {
                dp[i] += dp[i-it];
            }
        }
        return dp[amount];
    }
};
