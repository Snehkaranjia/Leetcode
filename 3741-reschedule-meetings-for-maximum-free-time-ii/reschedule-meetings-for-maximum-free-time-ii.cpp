class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {

        int n = startTime.size();
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);

        int ans = 0;
        for (int i = 0; i < gaps.size() - 1; i++) {
            ans = max(ans, gaps[i] + gaps[i + 1]);
        }

        int top1 = 0, top2 = 0, top3 = 0;
        for (int x : gaps) {
            if (x >= top1) {
                top3 = top2;
                top2 = top1;
                top1 = x;
            } else if (x >= top2) {
                top3 = top2;
                top2 = x;
            } else if (x >= top3) {
                top3 = x;
            }
        }

        for (int i = 0; i < n; i++) {
            int lgap = gaps[i];
            int rgap = gaps[i + 1];

            int maxi = max(lgap, rgap);
            int mini = min(lgap, rgap);
            int event = endTime[i] - startTime[i];

            bool sel1 = 0, sel2 = 0, sel3 = 0;
            if (maxi != top1)
                sel1 = 1;
            else {
                if (mini != top2)
                    sel2 = 1;
            }

            if (sel1) {
                if (top1 >= event)
                    ans = max(ans, event + lgap + rgap);
            } else if (sel2) {
                if (top2 >= event)
                    ans = max(ans, event + lgap + rgap);
            } else {
                if (top3 >= event)
                    ans = max(ans, event + lgap + rgap);
            }
        }
        return ans;
    }
};