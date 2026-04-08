class Solution {
public:
    int reverse(int n) {
        int revno=0;
        while(n!=0){
            int dig=n%10;
            if (revno > INT_MAX/10 || (revno == INT_MAX/10 && dig > 7)) return 0;
            if (revno < INT_MIN/10 || (revno == INT_MIN/10 && dig < -8)) return 0;
            revno=revno*10+dig;
            n=n/10;
        }
        return revno;
    }
};
