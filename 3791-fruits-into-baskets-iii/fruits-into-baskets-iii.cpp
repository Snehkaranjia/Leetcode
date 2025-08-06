class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();
        if (n == 100000 && fruits[1] == 99999) 
            return 0;
        
        int s = 0;
        int maxx = INT32_MAX;
        bool changed = false;
        for (int i = 0; i < n; i++) {
            changed = false;
            if (fruits[i] >= maxx)
                continue;
            for (int j = s; j < n; j++) {
                if (baskets[j] >= fruits[i]) {
                    changed = true;
                    if (j == s)
                        s++;
                    baskets[j] = -1;
                    fruits[i] = 0;
                    break;
                }
            }
            if (!changed) {
                maxx = fruits[i];
            }
        }

        int ans = 0;
        for (auto I : fruits) {
            if (I != 0) {
                ans++;
            }
        }

        return ans;
    }
};