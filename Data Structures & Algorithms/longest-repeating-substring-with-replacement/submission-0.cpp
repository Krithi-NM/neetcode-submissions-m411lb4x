class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int l=0;
        int r=0;
        int n=s.size();
        int maxfreq=0;
        int maxlen=0;
        
        while (r<n){
            count[s[r]-'A']++;
        maxfreq=max(maxfreq, count[s[r]-'A']);

        while((r-l+1)-maxfreq>k){
            count[s[l]-'A']--;
            l++;
        }
        maxlen=max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
    }
};
