class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1;
        int temp = n;
        int d = 0;
        while(temp > 0)
        {
            d = temp%10;
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