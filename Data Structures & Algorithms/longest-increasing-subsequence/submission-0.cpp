class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            int left = 0, right = tails.size() - 1;
            int pos = tails.size();

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (tails[mid] >= num) {
                    pos = mid;        
                    right = mid - 1;  
                } else {
                    left = mid + 1;   
                }
            }
            if (pos == tails.size()) {
                tails.push_back(num);
            } else {
                tails[pos] = num;
            }
        }
        return tails.size();
    }
};
