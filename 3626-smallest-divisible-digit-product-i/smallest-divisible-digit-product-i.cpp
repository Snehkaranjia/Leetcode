class Solution {

private:
    bool check(int num, int t)
    {
        int prod = 1;
        while(num > 0)
        {
            prod *= num%10;
            num/=10;
        }
        if(prod % t == 0)
            return true;
        return false;
    }

public:
    int smallestNumber(int n, int t) {
        while(!check(n, t))
        {
            n++;
        }
        return n;
    }
};