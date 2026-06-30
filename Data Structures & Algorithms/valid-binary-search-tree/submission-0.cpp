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
    bool fun(TreeNode* node,long long low,long long high)
    {
        if(node==NULL) return true;
        if(node->val <= low || node->val >= high)
        return false;
        return fun(node->left,low,node->val) && fun(node->right,node->val,high);
    }
    bool isValidBST(TreeNode* root) {
        
        return fun(root,INT_MIN,INT_MAX);
    }
};
