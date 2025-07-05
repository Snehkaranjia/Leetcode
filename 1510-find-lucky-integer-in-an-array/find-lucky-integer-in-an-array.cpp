class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> freq;
        for (auto& ch : arr)
            freq[ch]++;
        int ans = -1;
        for (auto& num : freq) {
            if (num.first == num.second)
                ans = max(ans, num.first);
        }
        return ans;
    }
};