/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxSumVal=INT_MIN;
    int solve(TreeNode* root) {
        if (root==NULL){
            return 0;
        }

        int leftsum= max(0,solve(root->left));
        int rightsum= max(0,solve(root->right));
        int currsum= leftsum+rightsum+root->val;
        maxSumVal=max(maxSumVal,currsum);
        return root->val+max(leftsum,rightsum);
    }
   int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSumVal;
   }
};
