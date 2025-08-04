class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n < 3)
            return n;

        int first = -1, second = -1;
        int lastType = 0;
        int cnt = 0, maxcnt = 0;

        for (int i = 0; i < n; i++) {
            int curr = fruits[i];

            if (curr == first || curr == second) {
                cnt++;
            } else {
                cnt = lastType + 1;
            }

            if (curr == second) {
                lastType++;
            } else {
                lastType = 1;
                first = second;
                second = curr;
            }

            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};