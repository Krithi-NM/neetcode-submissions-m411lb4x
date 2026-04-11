class Solution {
public:
    vector<int> countBits(int x) {
        vector<int> ans(x + 1);
        for(int i = 0; i <= x; i++){
            int num = i;
            int count = 0;
        
        while(num>0){
            num = num&(num-1);
            count++;
        }
        ans[i] = count;
        }
        return ans;
    }
};
