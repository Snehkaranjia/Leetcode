class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool allzero = true;
        int x = 0;
        int n = nums.size();
        for(int j=0; j<n; j++)
        {
            x = x^nums[j];
            if(nums[j] != 0)
                allzero = false;
        }
        if(allzero)
            return 0;
        if(x == 0)
            return n-1;
        return n;   
    }
};