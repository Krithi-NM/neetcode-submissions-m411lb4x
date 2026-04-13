class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;   
        
        while(n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);

        int sumofsquares=0;
        while(n!=0){
            int dig=n%10;
            sumofsquares += dig*dig;
            n=n/10;
        }
        n = sumofsquares; 
        }
        return n==1;
    }
};
