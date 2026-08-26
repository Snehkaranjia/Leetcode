/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL || root == p || root == q)
            return root;

        TreeNode* fl = lowestCommonAncestor(root->left, p, q);
        TreeNode* fr = lowestCommonAncestor(root->right, p, q);

        if(fl && fr)
            return root;
        else if(!fl)
            return fr;
        else
            return fl;
    }
};