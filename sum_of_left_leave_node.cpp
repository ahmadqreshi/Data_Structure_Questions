/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node
*/

class Solution {
public:
    int helper(TreeNode* root,int left) {
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL and left==1) { //left variable helps to add only left value in leftSum and rightSum 
            return root->val;
        }
        int leftSum = helper(root->left,1);
        int rightSum = helper(root->right,0);
        
        return leftSum + rightSum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL and root->right==NULL)
            return 0;
        return helper(root,0);
    }
};
