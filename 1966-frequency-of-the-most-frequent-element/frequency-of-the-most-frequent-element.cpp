class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long n = nums.size();
        if (n == 1)
            return 1;
        sort(nums.begin(), nums.end());
        long long l = 0, r = 0;
        long long ans = 0;
        long long sum = 0;
        while (r < n) {
            sum += nums[r];
            while (((sum + k) < (nums[r] * (r - l + 1))) && (r-l > 0))
            {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};