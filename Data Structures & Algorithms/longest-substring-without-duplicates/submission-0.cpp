class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int l=0;
        int r=0;
        int maxlen=0;
        int n=s.size();

        while (r<n){
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = max(hash[s[r]] + 1, l); 
            }
        int len=r-l+1;
        maxlen=max(len,maxlen);
        hash[s[r]]=r;
        r++;
    }
    return maxlen;
    }
};
