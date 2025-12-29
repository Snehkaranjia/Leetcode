class Solution {
    unordered_map<string, vector<char>> mpp;
    unordered_map<string, bool> memo;

public:
    bool dfs(string prev, int idx, string curr) {
        int n = prev.size();
        if (memo.count(prev) && idx == 0)
            return memo[prev];

        if (idx == n - 1) {
            if (curr.size() == 1)
                return true;
            return memo[prev] = dfs(curr, 0, "");
        }

        string pair = prev.substr(idx, 2);
        if (mpp.count(pair)) {
            for (char c : mpp[pair]) {
                curr.push_back(c); 
                if (dfs(prev, idx + 1, curr))
                    return true; 
                curr.pop_back(); 
            }
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& a : allowed) {
            mpp[a.substr(0, 2)].push_back(a[2]);
        }
        return dfs(bottom, 0, "");
    }
};