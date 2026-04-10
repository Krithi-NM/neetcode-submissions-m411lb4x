class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currsum = 0;
        int maxsum = INT_MIN;

        for(int val:nums){
        if(currsum<0){
            currsum=0;
        }
           currsum +=val;
           maxsum = max(maxsum, currsum);
        }
        return maxsum;
    
    }
};
