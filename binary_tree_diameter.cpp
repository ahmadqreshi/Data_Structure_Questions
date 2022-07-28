//maximum distance between any two nodes  :- distance go through paths
//can include root value or not 
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree() { 
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
int height(Node* root) {
    if(root==NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left,right);
}
int diameter(Node* root) { // Time Complexity O(n2)
    if(root==NULL)
        return 0;
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    return max(D1,max(D2,D3));
}
int main()
{
   Node* root = buildTree(); //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
   cout<<"The Diameter of the tree is : "<<diameter(root);
    return 0;
}
