class Solution {
public:
    
    void swapNodes(TreeNode* root) {
        if(root) {
            swap(root->left,root->right);
            swapNodes(root->left);
            swapNodes(root->right);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root) {
            swapNodes(root);
        }
        return root;
    }
};
