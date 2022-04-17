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
        if(root->right!=NULL)  root->right=increasingBST(root->right);
        if(root->left!=NULL)
        {
          TreeNode* leftTree = increasingBST(root->left);
          root->left=NULL;
            
          TreeNode* p=leftTree;
          while(p->right!=NULL) p=p->right;
          p->right = root;
            
          root=leftTree;
        }
        return root;
    }
};