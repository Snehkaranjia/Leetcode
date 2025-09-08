class Solution {
private:
    bool checkNZ(int n1, int n2) {
        while (n1 > 0) {
            if (n1 % 10 == 0)
                return false;
            n1 /= 10;
        }
        while (n2 > 0) {
            if (n2 % 10 == 0)
                return false;
            n2 /= 10;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (checkNZ(i, n - i)) {
                return {i,n-i};
            }
        }
        return {};
    }
};