class Solution {
public:
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = left;
        while (inorder[mid] != rootVal) {
            mid++;
        }
        root->left = helper(preorder, inorder, left, mid - 1);
        root->right = helper(preorder, inorder, mid + 1, right);

        return root;
    }
};