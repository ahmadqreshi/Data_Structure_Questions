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
Node* insert(Node* root, int val) {
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
bool search(Node* root,int key) {
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
void printInRange(Node* root,int k1,int k2) {
    if(root==NULL)
        return;
    if(k1<= root->key and root->key <= k2) {
        printInRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printInRange(root->right,k1,k2);
    }else if(root->key > k2) {
        printInRange(root->left,k1,k2);
    }else {
        //root->key < k1
        printInRange(root->right,k1,k2);
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
    printInRange(root,1,4);
    return 0;
}
//OUTPUT :- 1 2 3
