int calculateHeight(Node* root) {
    if(root==NULL) {
        return 0;
    }
    int h1 = calculateHeight(root->left);
    int h2 = calculateHeight(root->right);
    
    return 1 + max(h1,h2);
}
