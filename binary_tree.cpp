#include <iostream>
#define newLine cout<<endl
#define print cout<<
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
//first create individual nodes and while returning they are linked
//below graph are created by using preOrder build
//take input on runtime
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

void printPreOrder(Node* root) { // pass by value 
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(Node* root) { // pass by value
    if(root==NULL)
        return;
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}
void printPostOrder(Node* root) { // pass by value : BOTTOM UP Approach Used for solvig question
    if(root==NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    //input //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    // int n = sizeof(arr)/sizeof(int);
    // while(n>=0) {
    //     buildTree();
    //     n--;
    // }
    print"take input on runtime";
    newLine;
    Node* root = buildTree();
    print"Pre Order Traversal"<<endl;
    printPreOrder(root);
    newLine;
    print"In Order Traversal"<<endl;
    printInOrder(root);
    newLine;
    print"Post Order Traversal"<<endl;
    printPostOrder(root);
    return 0;
}
