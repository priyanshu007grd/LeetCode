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
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root==NULL) return root;
        
        TreeNode* leftTree = increasingBST(root->left);
        TreeNode* rightTree = increasingBST(root->right);
        
        if(leftTree!=NULL)
        {
            TreeNode* p=leftTree;
            while(p->right!=NULL) p=p->right;
            p->right = root;
        }

        
        root->left=NULL;
        root->right=rightTree;
        
        return leftTree==NULL?root:leftTree;
    }
};