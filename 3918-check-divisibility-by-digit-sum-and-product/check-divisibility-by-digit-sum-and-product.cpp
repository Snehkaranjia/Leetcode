class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0, prod=1;
        int temp = n;
        while(temp > 0)
        {
            int d = temp%10;
            sum += d;
            prod *= d;
            temp = temp/10;
        }
        int total = sum+prod;
        if(n % total)
            return false;
        return true;
    }
};