class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lsum = 0, rsum = 0, lcnt = 0, rcnt = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '?')
                i < n / 2 ? lcnt++ : rcnt++;
            else
                i < n / 2 ? lsum += (num[i] - '0') : rsum += (num[i] - '0');
        }

        if (lcnt + rcnt == 0)
            return lsum == rsum ? false : true;
        else if ((lcnt + rcnt) % 2 == 1)
            return true;
        else
            return (lsum - rsum) == ((rcnt - lcnt) * 9) / 2 ? false : true;
    }
};