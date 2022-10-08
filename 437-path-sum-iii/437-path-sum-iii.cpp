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
    void solve(TreeNode* root,long long int targetSum,map<long long int,int> m,int &count,long long int sum)
    {
        if(root==NULL) return;
        sum+=root->val;
        if(m.find(sum-targetSum)!=m.end())
        {
            count+=m[sum-targetSum];
        }
        m[sum]++;
        solve(root->left,targetSum,m,count,sum);
        solve(root->right,targetSum,m,count,sum);
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        int count=0;
        
        map<long long int,int> m;
        m[0]=1;
        
        long long int sum=0;
        solve(root,targetSum,m,count,sum);
        return count;
    }
};