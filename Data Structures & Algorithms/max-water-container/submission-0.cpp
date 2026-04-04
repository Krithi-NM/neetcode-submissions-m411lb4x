class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater=0;
        int n=heights.size();
        int lp=0;
        int rp=n-1;

        while(lp<rp){
            int w=rp-lp;
            int ht=min(heights[lp],heights[rp]);
            int currwater=ht*w;
            maxwater=max(currwater,maxwater);
            if (heights[lp]<heights[rp]){
                lp++;
            } else{
                rp--;
            }
        }

    return maxwater;
    }
};
