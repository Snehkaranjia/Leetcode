class Solution {

private:
    void solve(vector<int>& can,set<vector<int>> &ans, vector<int> &curr, int rem, int idx)
    {
        if(idx == can.size())
        {
            if(rem == 0)
            {
                ans.insert(curr);
            }
            return;
        }

        if(rem >= can[idx])
        {
            curr.push_back(can[idx]);
            solve(can, ans, curr, rem - can[idx], idx + 1);
            curr.pop_back();
        }

        while(idx + 1 < can.size() && can[idx]==can[idx+1])
            idx++;

        solve(can, ans, curr, rem, idx+1);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        set<vector<int>> ans;
        solve(candidates, ans, curr, target, 0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};