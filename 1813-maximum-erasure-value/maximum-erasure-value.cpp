class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, currSum = 0, s = 0;
        unordered_set<int> visited;

        for (int e = 0; e < nums.size(); e++) {
            while (visited.find(nums[e]) != visited.end()) {
                visited.erase(nums[s]);
                currSum -= nums[s];
                s++;
            }

            currSum += nums[e];
            visited.insert(nums[e]);

            ans = max(ans, currSum);
        }

        return ans;
    }
};