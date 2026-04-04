class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
    int n=intervals.size();

    //int start=0;
    int currend=intervals[0][1];
    int removals=0;

     for (int i=1;i<n;i++) {
         if (intervals[i][0] <currend){
             removals++;
         }
         else {
             currend=intervals[i][1];
         }
     }
    return removals;
    }
};
