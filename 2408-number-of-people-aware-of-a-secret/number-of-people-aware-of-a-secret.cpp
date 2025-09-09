class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> pplKnow(n + 1, 0);
        int mod = 1e9 + 7;
        pplKnow[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j <= n && j < i + forget; j++) {
                pplKnow[j] += pplKnow[i];
                pplKnow[j] %= mod;
            }
        }
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            ans += pplKnow[i];
            ans %= mod;
        }
        return ans;
    }
};