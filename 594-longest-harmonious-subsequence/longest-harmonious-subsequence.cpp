class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;
        for(auto it:nums)
            freq[it]++;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if((nums[i] - nums[i-1]) == 1)
            {
                if(ans < freq[nums[i]] + freq[nums[i-1]])
                    ans = freq[nums[i]] + freq[nums[i-1]];
            }
        }
        return ans;
    }
};