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
//https://www.interviewbit.com/problems/recover-binary-search-tree/
class Solution 
{
    public :
	TreeNode *first,*second;
    TreeNode *prev;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        
        inorder(root->left);
        if(prev && prev->val>root->val)
        {
            if(first==NULL) first=prev;
            second=root;
        }
        prev=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root)
    {
        first=second=prev=NULL;
        inorder(root);
        swap(first->val,second->val);
    }
};