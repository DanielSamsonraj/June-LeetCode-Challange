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
    int sum = 0;
    void dfs(TreeNode* root, string s) {
        if(root) {
            if(!root->left and !root->right) {
                s += to_string(root->val);
                sum += stoi(s);
            }
            dfs(root->left, s + to_string(root->val));
            dfs(root->right, s + to_string(root->val));
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        return sum;
    }
};
