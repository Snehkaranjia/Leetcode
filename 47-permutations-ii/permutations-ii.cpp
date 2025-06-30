class Solution {

private:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j = index; j<nums.size(); j++)
        {
            if(nums[index] == nums[j] && index!=j)
                continue;
            swap(nums[index], nums[j]);
            solve(nums, index+1, ans);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, index, ans);
        return ans;
    }
};