class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxAND = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int cntMA = 0;
        for(auto e : nums)
        {
            if(e == maxAND)
                cntMA++;
            else
                cntMA = 0;
            ans = max(ans, cntMA);
        }
        return ans;
    }
};