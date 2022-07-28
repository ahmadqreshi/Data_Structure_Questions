//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
class Solution {
public:
     bool find(TreeNode* root1, TreeNode* root2){
        if(root1==NULL and root2==NULL)
            return true;
        if(root1==NULL or root2==NULL)
            return false;
        if(root1->val != root2->val)
            return false;
        
        bool checkOuterPart = find(root1->left, root2->right); // equates outer values from both sides
        bool checkInnerPart = find(root1->right,root2->left); // equates inner values from both sides
        return checkOuterPart and checkInnerPart; // hence for a tree to be mirror itself both inner and outer part should be equal
    }
    bool isSymmetric(TreeNode* root) {
        return find(root->left, root->right);
    }
};
