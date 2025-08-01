class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto &vec : nums)
            sort(vec.begin(), vec.end());
        int ans = 0;
        for(int j=nums[0].size() - 1; j>=0; j--)
        {
            int maxi = INT_MIN;
            for(int i=0; i<nums.size(); i++)
            {
                maxi = max(maxi, nums[i][j]);
            }
            ans += maxi;
        }
        return ans;
    }
};