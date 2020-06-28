class Solution {
private: 
    void dfs(vector<string> &res, unordered_map<string, multiset<string>> &map, string src){
        while(!map[src].empty()){
            string dest = *(map[src].begin());
            map[src].erase(map[src].begin());
            dfs(res, map, dest);
        }
        res.push_back(src);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int len = tickets.size(), i;
        vector<string> res;
        unordered_map<string, multiset<string>> map;
        for(i=0; i<len;++i) map[tickets[i][0]].insert(tickets[i][1]);
        dfs(res, map, "JFK");
        std::reverse(res.begin(),res.end());
        return res;
    }
};
