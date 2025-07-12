class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> cont1(n + 1, 0);
        int pof2 = 1;

        for (int i = 1; i <= n; i++) {
            if (pof2 * 2 == i) {
                pof2 = i;
            }

            cont1[i] = cont1[i - pof2] + 1;
        }

        return cont1;
    }
};