#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};
void preOrderTraversal(Node* root,int &ans) {
    if(root == NULL)
        return;
    ans += root->key;
    preOrderTraversal(root->left,ans);
    preOrderTraversal(root->right,ans);
}
int sumBT(Node* root)
{
    int ans = 0;
    preOrderTraversal(root,ans);
    return ans;
}
