//Binary Search Tree is a Binary tree in which left subtree is less than equal to node 
// and right subtree is greater than root
//Inorder traversal of BST gives sorted output
#include <iostream>
using namespace std;
class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) { // creation
    if(root==NULL) {
        return new Node(val);
    }
    if(val <= root->key) {
        root->left = insert(root->left,val);
    } else {
        root->right = insert(root->right,val);
    }
    return root;
}
void inorderTraversal(Node* root) {
    if(root== NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->key<<" ";
    inorderTraversal(root->right);
}
bool search(Node* root,int key) { //Searching
    if(root==NULL)
        return false;
    if(root->key==key)
        return true;
    if(key < root->key) {
        return search(root->left,key);
    }else {
        return search(root->right,key);
    }
}

int main()
{
    Node* root = NULL;
    int arr[] = {3,2,5,6,9,7,1};
    for(int i : arr) {
        root = insert(root,i);
    }
    inorderTraversal(root); 
    cout<<endl;
    if(search(root,1)) {
        cout<<"Value found"<<endl;
    }else {
        cout<<"No Value found"<<endl;
    }
    return 0;
}
//OUTPUT - 
/*
1 2 3 5 6 7 9 
Value found
*/
