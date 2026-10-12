class Solution {
public:
    int subtractProductAndSum(int n) {
        int n2=1, n3=0;
        while (n >0)
        {
            n2=n2*(n%10);
            n3=n3+(n%10);
            n=n/10;
        }
        return n2-n3;
    }
};