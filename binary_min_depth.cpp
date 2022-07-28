//The minimum depth of a binary tree is the number of nodes from the root node to the nearest leaf node
int minDepth(Node *root) {
        if(root==NULL)
            return 0;
        int h1 = minDepth(root->left);
        int h2 = minDepth(root->right);
        return 1+min(h1,h2);
}
