class Solution {
public:
    vector<string> result;
    void solve(string digits, int index, string current, vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (int i = 0; i < letters.size(); i++) {
            solve(digits, index + 1, current + letters[i], mapping);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        solve(digits, 0, "", mapping);
        return result;
    }
};