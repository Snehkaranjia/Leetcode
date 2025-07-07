class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int days = 0;
        for (auto& e : events) {
            days = max(days, e[1]);
        }

        set<int> occ;
        for (int d = 1; d <= days; d++) {
            occ.insert(d);
        }

        int count = 0;
        for (auto& e : events) {
            auto it = occ.lower_bound(e[0]);
            if (it != occ.end() && *it <= e[1]) {
                count++;
                occ.erase(it); 
            }
        }

        return count;
    }
};