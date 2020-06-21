class Solution { 
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;--i){
            for(int j=m-1; j>=0; --j){
                if(i+1==n && j+1 == m){
                    dp[i][j] = max(1-dungeon[i][j],1);
                    continue;
                }
                if(j+1<m){
                    dp[i][j] = max(dp[i][j+1] - dungeon[i][j],1);
                }
                if(i+1<n){
                    if(dp[i][j])
                        dp[i][j] = min(dp[i][j],max(dp[i+1][j] - dungeon[i][j],1));
                    else 
                        dp[i][j] = max(dp[i+1][j]-dungeon[i][j],1);
                }
            }
        }

        return dp[0][0];
    }
};
