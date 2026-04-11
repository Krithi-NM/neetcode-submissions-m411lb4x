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
    bool isidentical(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL || root2==NULL){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        return isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right);
    }
    
     bool isSubtree(TreeNode* root, TreeNode* subtree) {
        if(root==NULL && subtree==NULL){
            return true;
        }
        if(root==NULL || subtree==NULL){
            return false;
        }
        if(root->val==subtree->val){
            if(isidentical(root,subtree)){
                return true;
            }
        }

        int isleftsubtree = isSubtree(root->left,subtree);
         if (!isleftsubtree){
            return isSubtree(root->right,subtree);
        }
        return true;
        }
};
