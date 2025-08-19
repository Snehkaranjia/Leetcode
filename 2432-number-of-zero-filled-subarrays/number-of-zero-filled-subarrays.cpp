class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int lastNZ = -1;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                lastNZ = j;
            } else {
                int len = j - lastNZ;
                ans += len;  
            }
        }
        return ans;
    }
};