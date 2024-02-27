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
    int height(TreeNode* root, int &d)
    {
        if(root == NULL)
            return 0;
        
        int lH = height(root->left, d);
        int rH = height(root->right, d);
        d = max(d, lH + rH);
        return 1 + max(lH, rH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        if(root == NULL)
            return 0;
        height(root, diameter);
        return diameter;
    }
};