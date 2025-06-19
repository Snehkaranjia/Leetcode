class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return 1;
        sort(nums.begin(), nums.end());
        int ans = 0;
        int s = 0, e=1;
        for(int i=1; i<n;i++)
        {
            if(nums[i] - nums[s] <= k)
                continue;
            else
            {
                s=i;
                ans++;
            }
        }
        return ans+1;
    }
};