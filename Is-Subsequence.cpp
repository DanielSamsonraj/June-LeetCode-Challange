class Solution {
public:
    
    bool check(vector<bool> arr, int index) {
        for(int i=0;i<index;i++) {
            if(arr[i]) {
                return true;
            }
        }
        return false;
    }
    
    bool isSubsequence(string s, string t) {
        if(s.size() == 0 ) return true;
        if(s.size() != 0 and t.size() == 0) return false;
        vector<vector<bool>> dp(s.size(), vector<bool> (t.size(), false));
        for(int i=0;i<s.size();i++) {
            for(int j=0;j<t.size();j++) {
                if(s[i] == t[j]) {
                    if(i==0) {
                        dp[i][j] = true;
                    }
                    else if(check(dp[i-1], j)) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        for(auto it : dp[s.size()-1]) {
            if(it) {
                return true;
            }
        }
        return false;
    }
};
