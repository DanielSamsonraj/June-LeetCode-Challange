class RandomizedSet {
private:
    vector<int> vec;
    unordered_map<int, int> map;

public:
    RandomizedSet() { }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        vec.emplace_back(val);
        map[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        map[vec[map[val]] = vec[vec.size() - 1]] = map[val];  
        vec.pop_back();
        return map.erase(val);
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
