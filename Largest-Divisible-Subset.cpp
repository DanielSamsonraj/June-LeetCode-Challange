class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        int n = nums.size(), i, j;
        vector<pair<int,int>> dp(n);
        dp[0] = {1, -1};
        sort(nums.begin(), nums.end());
        int index;
        for(i=1;i<n;i++) {
            int mm = 0;
            index = -1;
            for(j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0) {
                    if(mm <= dp[j].first) {
                        mm = dp[j].first;
                        index = j;
                    }
                }
            }
            dp[i] = { 1 + mm, index };
        }
        int mm = 0;
        for(i=0;i<dp.size();i++) {
            if(mm <= dp[i].first) {
                mm = dp[i].first;
                index = i;
            }
        }
        vector<int> res;
        i = index;
        while(i >= 0) {
            res.push_back(nums[i]);
            i = dp[i].second;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
