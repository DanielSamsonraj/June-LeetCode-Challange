class Solution {
public:
    pair<int,int> findMin(vector<pair<int,int>> dp, int pos) {
        int sum = 100000, i;
        pair<int, int> p;
        for(i=0;i<pos;i++) {
            if(dp[i].first + dp[i].second != 0 and dp[i].first + dp[i].second < sum) {
                sum = dp[i].first + dp[i].second;
                p = dp[i];
            }
        }
        return p;
    }
    
    int Solve(vector<vector<int>> costs, int bCost) {
        vector<vector<pair<int,int>>> dp(costs.size()/2 + 1, vector<pair<int,int>> (costs.size()));
        int i, j;
        for(i=0;i<costs.size();i++) {
            dp[1][i] = {costs[i][0], bCost - costs[i][1]};
        }
        for(j=2;j<=costs.size()/2;j++) {
            dp[j][0] = {0, 0};
        }
        for(i=2;i<=costs.size()/2;i++) {
            for(j=i-1;j<costs.size();j++) {
                pair<int,int> p = findMin(dp[i-1], j);
                dp[i][j] = {costs[j][0] + p.first , abs(p.second - costs[j][1])};
            }
        }
        int minCost = 100000;
        for(i=0;i<costs.size();i++) {
            int sum = dp[costs.size()/2][i].first + dp[costs.size()/2][i].second;
            if(sum != 0)
            minCost = min(minCost, sum);
        }
        return minCost;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalBCost = 0, totalACost = 0;
        for(auto it : costs) {
            totalBCost += it[1];
        }
        return Solve(costs,totalBCost);
    }
};
