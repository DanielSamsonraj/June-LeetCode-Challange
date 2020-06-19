// Rabin Carp Algorithm
class Solution {
public:
    vector<long long> pow, pow2;
    long long p = 1000007, p2 = 100009, mod = 1000000007;
    void modifyHash(pair<long long, long long> &hash, int hashLength, char current, bool rollHash, char toRemove) {
        if(rollHash) {
            hash.first = (hash.first - (toRemove * pow[hashLength-1]) % mod + mod) % mod;
            hash.second = (hash.second - (toRemove * pow2[hashLength-1]) % mod + mod) % mod;
        }
        hash.first = (hash.first * p + current) % mod;
        hash.second = (hash.second * p2 + current) % mod;
    }
    
    void precompute() {
        if(pow.size() == 0) {
            pow.resize(100001);
            pow2.resize(100001);
            pow[0] = pow2[0] = 1;
            for(int i = 1; i <= 100000; i++) {
                pow[i] = (pow[i-1] * p) % mod;
                pow2[i] = (pow2[i-1] * p2) % mod;
            }
        }
    }

    string longestDupSubstring(string S) {
        precompute();
        int lengthAnswer = 0, start = -1;
        int l = 1, r = S.size();
        set<pair<long long, long long>> st;
        pair<long long, long long> hash = {0, 0};
        
        while(l <= r) {
            
            int mid = (l + r) / 2;
            bool duplicate = false;
            
            st.clear();
            hash.first = hash.second = 0;
            
            for(int i = 0; i < mid; i++) modifyHash(hash, mid, S[i], false, NULL);
            st.insert(hash);
            
			int pos = mid;
            while(pos < S.size()) {
                modifyHash(hash, mid, S[pos], true, S[pos-mid]);
                pos++;
            
                if(st.find(hash) != st.end()) {
                    duplicate = true;
                    start = pos-mid;
                    break;
                }
                st.insert(hash);
            }
            if(duplicate) {
                lengthAnswer = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(start == -1) return "";

        string answer;
        for(int i = 0; i < lengthAnswer; i++) answer += S[start+i];
        return answer;
    }
};
