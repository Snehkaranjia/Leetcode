class Solution {

private:
    void solve(vector<int>& can,vector<vector<int>> &ans, vector<int> &curr, int rem, int idx)
    {
        if(idx == can.size())
        {
            if(rem == 0)
            {
                ans.push_back(curr);
            }
            return;
        }

        if(rem >= can[idx])
        {
            curr.push_back(can[idx]);
            solve(can, ans, curr, rem - can[idx], idx);
            curr.pop_back();
        }

        solve(can, ans, curr, rem, idx+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(candidates, ans, curr, target, 0);
        return ans;
    }
};