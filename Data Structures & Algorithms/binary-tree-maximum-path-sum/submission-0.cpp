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
     int mx = INT_MIN;
    int dfs(TreeNode*node)
    {
        if(node==NULL)
        return 0;
        int leftmax =dfs(node->left);
        int rightmax = dfs(node->right);
        if(leftmax<0) leftmax = 0;
        if(rightmax<0) rightmax=0;
        mx = max(mx,leftmax+rightmax+node->val);
        return node->val + max(leftmax,rightmax);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
