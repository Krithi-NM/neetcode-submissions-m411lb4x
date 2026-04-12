class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            int lastdig=n&1;
            count+=lastdig;
            n=n>>1;
        }
        return count;

    }
};
