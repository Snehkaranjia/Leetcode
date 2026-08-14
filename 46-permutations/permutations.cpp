class Solution {

private:
    void solve(vector<int>& nums, vector<vector<int>> &ans, int n, int idx)
    {
        if(idx >= n)
        {
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<n; i++)
        {
            swap(nums[idx], nums[i]);
            solve(nums, ans, n, idx+1);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(nums, ans, n, 0);
        return ans;
    }
};