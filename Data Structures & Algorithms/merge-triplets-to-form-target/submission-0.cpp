class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];

        bool foundX = false, foundY = false, foundZ = false;

        for(auto &t : triplets){
            if(t[0] <= x && t[1] <= y && t[2] <= z){
                if(t[0] == x) foundX = true;
                if(t[1] == y) foundY = true;
                if(t[2] == z) foundZ = true;
            }
        }

        return foundX && foundY && foundZ;
    }
};