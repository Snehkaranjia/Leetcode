class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int last0 = -1;
        int ans = 0;
        bool zero = false;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                if (!zero) {
                    zero = true;
                    last0 = j;
                } else {
                    ans = max(ans, j - i - 1);
                    i = last0 + 1; 
                    last0 = j;   
                }
            }
            j++;
        }
        ans = max(ans, j - i - 1);
        return ans;
    }
};