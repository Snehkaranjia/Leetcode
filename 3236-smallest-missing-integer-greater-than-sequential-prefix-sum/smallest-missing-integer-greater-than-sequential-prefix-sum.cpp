class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxsum = nums[0];
        int n = nums.size();
        
        if(n == 1)
            return nums[0] + 1;

        unordered_set<int> check(nums.begin(), nums.end());

        for(int i=1; i<n; i++)
        {
            if(nums[i] == nums[i-1] + 1)
                maxsum += nums[i];
            else
                break;
        }

        while(check.count(maxsum))
            maxsum++;

        return maxsum;
    }
};