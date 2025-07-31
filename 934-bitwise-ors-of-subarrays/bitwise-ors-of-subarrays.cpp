class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int> distOR;
        set<int> prev;
        for(auto &num : arr)
        {
            set<int> curr;
            curr.insert(num);
            for(auto &ele : prev)
                curr.insert(ele | num);
            prev = curr;
            distOR.insert(curr.begin(), curr.end());
        }
        return distOR.size();
    }
};