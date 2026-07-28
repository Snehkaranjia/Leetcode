class Solution {
public:
    int maxProduct(int n) {
        int l1 = 0,l2 = 0;
        while(n>0)
        {
            if(n%10 > l1)
            {
                l2 = l1;
                l1 = n%10;
            }
            else if(n%10 > l2)
                l2 = n%10;
            n/=10;
        }
        return l1*l2;
    }
};