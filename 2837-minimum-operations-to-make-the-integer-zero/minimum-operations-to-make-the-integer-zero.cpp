class Solution {
#define ll long long
private:
    int count(ll num) {
        int cnt = 0;
        while (num != 0) {
            if ((num & 1ll) == 1)
                cnt++;
            num = num >> 1;
        }
        return cnt;
    }

public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 <= num2)
            return -1;
        if (num2 == 0)
            return count(num1);
        ll n1 = num1, n2 = num2;
        int c = 0;
        while (n1 > n2) {
            n1 = n1 - n2;
            c++;
            if (c >= count(n1) && c <= n1)
                return c;
        }
        return -1;
    }
};