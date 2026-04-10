class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { //non decreasing watch out
        int n=numbers.size();
        int i=0;
        int j=n-1;

        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
               return{i+1, j+1}; // watch out
            }else if(sum<target){
                i++;
            }else{
                j--;
            }
        }
        return {};
    }
};
