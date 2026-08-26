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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        long long maxi = 0;
        while(!q.empty())
        {
            int s = q.size();
            long long f = q.front().second;;
            long long l = q.back().second;
            maxi = max(maxi, l-f+1);
            for(int i=0; i<s; i++)
            {
                pair<TreeNode*, int> fn = q.front();
                q.pop();
                long long idx = fn.second - f;
                if(fn.first->left)
                    q.push({fn.first->left, 2*idx});
                if(fn.first->right)
                    q.push({fn.first->right, 2*idx+1});
            }
        }
        return maxi;
    }
};