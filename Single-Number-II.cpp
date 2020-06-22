class Solution {
public:
    int convertToDecimal(vector<int> bits) {
        long long int base = 1, num = 0;
        for(int i=bits.size() - 1; i>=0; i--) {
            num += bits[i] * base;
            base *= 2;
        }
        return num;
    }
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        for(auto it : nums) {
            bitset<32> num(it);
            for(int i=31;i>=0;i--) {
                bits[31-i] += num[i];
            }
        }
        for(int i=0;i<bits.size();i++) {
            bits[i]%=3;
        }
        
        return convertToDecimal(bits);
    }
};
