class Solution {

private:
    void solve(vector<int> nums, int index, set<vector<int>> &s)
    {
        if(index >= nums.size())
        {
            s.insert(nums);
            return;
        }

        for(int j = index; j<nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, index+1, s);
            //backtrack
            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        int index = 0;
        solve(nums, index, s);
        vector<vector<int>> ans;
        for(auto &vec : s)
        {
            ans.push_back(vec);
        }
        return ans;
    }
};