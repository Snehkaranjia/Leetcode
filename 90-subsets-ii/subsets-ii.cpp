class Solution {

private:
    void solve(vector<int>& nums, vector<int> &curr, vector<vector<int>> &ans, int i, int n)
    {
        if(i >= n)
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, curr, ans, i+1, n);
        curr.pop_back();

        while(i+1 < n && nums[i] == nums[i+1])
            i++;

        solve(nums, curr, ans, i+1, n);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums, curr, ans, 0, n);
        return ans;
    }
};