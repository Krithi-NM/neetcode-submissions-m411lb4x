class Solution {
public:
    void solve(vector<int>& arr, int idx, int target, vector<vector<int>> &ans, vector<int> &comb) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;

            comb.push_back(arr[i]);
            solve(arr, i + 1, target - arr[i], ans, comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(arr.begin(), arr.end());
        solve(arr, 0, target, ans, comb);
        return ans;
    }
};