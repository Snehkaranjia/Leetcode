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

private:
    int solve(TreeNode* &root, int &dia)
    {
        if(root==NULL)
            return 0;

        int dl = solve(root->left, dia);
        int dr = solve(root->right, dia);
        dia = max(dia, dl+dr);

        return max(dl, dr) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        solve(root, dia);
        return dia;
    }
};