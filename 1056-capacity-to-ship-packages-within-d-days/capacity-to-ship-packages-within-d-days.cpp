class Solution {
private:
    bool possible(vector<int>& weights, int days, int ele) {
        int day = 1, sum = 0;
        for (auto it : weights) {
            if (sum + it > ele) {
                sum = it;
                day++;
                if (day > days)
                    return false;
            } else {
                sum += it;
            }
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for (auto it : weights)
            r += it;

        int mid = l + (r - l) / 2;
        while (l <= r) {
            if (possible(weights, days, mid))
                r = mid - 1;
            else
                l = mid + 1;
            mid = l + (r - l) / 2;
        }

        return l;
    }
};