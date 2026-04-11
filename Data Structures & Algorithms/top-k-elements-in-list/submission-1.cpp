class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>freq;

       for(int num:nums){
        freq[num]++;
       }
       priority_queue<pair<int,int>>pq;//max heapdefault

       for(auto it:freq){
        pq.push({it.second,it.first});
       }
       vector<int>ans;

       for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);//q.top() → gives pair (freq, num)
                                       //.second → gives number
        pq.pop();
       }
       return ans;

    }
};
