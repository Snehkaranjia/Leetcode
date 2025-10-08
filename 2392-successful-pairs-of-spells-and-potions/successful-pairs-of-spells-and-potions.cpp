class Solution {
private:
    int binsearch(int sp, vector<int>& pt, long long sc, int m)
    {
        int i = 0, j = m - 1, mid;
        while (i <= j)
        {
            mid = i + (j - i) / 2;
            if ((long long)pt[mid] * sp >= sc)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return m - i;
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        for (int i = 0; i < n; i++)
        {
            int cnt = binsearch(spells[i], potions, success, m);
            pairs.push_back(cnt);
        }
        return pairs;
    }
};
