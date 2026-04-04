class Solution {
public:
    int search(vector<int>& arr, int tar) {
        int n=arr.size();
        int start=0;
        int end=n-1;

        while(start<=end){
        int mid= start+(end-start)/2;

        if (tar>arr[mid]){
            start=mid+1;
        }else if (tar<arr[mid]){
            end=mid-1;
        }else{
            return mid;
        }
        }
        return -1;
    }
};
