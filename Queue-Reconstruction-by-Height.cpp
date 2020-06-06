class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>> v;
        int i,j;
        for(i=0;i<people.size();i++) {
            v.push_back({people[i][0],people[i][1]});
        }
        sort(v.begin(),v.end());
        vector<int> ans(v.size(),-1);
        vector<int> res(v.size());
        for(i=0;i<v.size();i++) {
            int cnt = 0,k=0;
            for(j=0;j<v.size();j++) {
                if(cnt == v[i].second) {
                    while(ans[j] != -1 and j<v.size()) {
                        j++;
                    }
                    break;
                } 
                if(ans[j] == -1 or ans[j] >= v[i].first) {
                    cnt++;
                }
            }
            ans[j] = v[i].first;
            res[j] = i;
        }
        vector<vector<int>> finalRes;
        for(auto it:res) {
            vector<int> a = {v[it].first, v[it].second};
            finalRes.push_back(a);
        }
        return finalRes;
    }
};
