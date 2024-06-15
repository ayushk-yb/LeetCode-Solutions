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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        
        int lH = height(root->left);
        int rH = height(root->right);

        if(abs(lH - rH) > 1){
            return false;
        }

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        if(l && r){
            return true;
        }

        return false;
    }
};