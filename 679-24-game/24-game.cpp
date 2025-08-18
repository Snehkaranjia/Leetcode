class Solution {
public:
    const double epsilon = 1e-6;
    bool f(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24) <= epsilon;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                vector<double> v;
                for (int k = 0; k < nums.size(); k++) {
                    if (k == i or k == j)
                        continue;
                    v.push_back(nums[k]);
                }
                double a = nums[i];
                double b = nums[j];
                vector<double> p = {a + b, b - a, a - b, a * b};
                if (abs(b) > 0.0)
                    p.push_back(a / b);
                if (abs(a) > 0.0)
                    p.push_back(b / a);
                for (int k = 0; k < p.size(); k++) {
                    v.push_back(p[k]);
                    if (f(v))
                        return true;
                    v.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int i = 0; i < cards.size(); i++) {
            nums.push_back(cards[i] * 1.0);
        }
        return f(nums);
    }
};