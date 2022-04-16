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
class Solution 
{
public:
    void travel(TreeNode* root, int &cur_sum)
    {
        if (!root) return;
        
        if (root->right) travel(root->right,cur_sum);
        root->val = (cur_sum += root->val);
        if (root->left) travel(root->left,cur_sum);
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        int cur_sum=0;
        travel(root,cur_sum);
        return root;
    }
};