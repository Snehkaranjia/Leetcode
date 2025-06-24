class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int s = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                s = max(s, i - k);
                e = min(i + k + 1, n);
                for (int j = s; j < e; j++) {
                    ans.push_back(j);
                }
                s = e;
            }
        }
        return ans;
    }
};