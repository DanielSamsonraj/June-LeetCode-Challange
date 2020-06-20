class Solution {
public:
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1;i<=n;i++) {
            str += (i + '0');
        }
        do {
            k--;
            if(!k) return str;
        }while(next_permutation(str.begin(), str.end()));
        return str;
    }
};
