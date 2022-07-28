#include <iostream>
#include <queue>

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
Node* preOrderBuildTree() { 
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node* n = new Node(d);
    n->left = preOrderBuildTree();
    n->right = preOrderBuildTree();
    return n;
}
Node* levelOrderBuild() { // take input without using recursion // use queue to store root first and then left and right child of the front
    int val;
    cin>>val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        int val1,val2;
        cin>>val1>>val2;
        if(val1!=-1) {
            current->left = new Node(val1);
            q.push(current->left);
        }
        if(val2!=-1) {
            current->right = new Node(val2);
            q.push(current->right);
        }
    }
    return root;
}
void printLevelOrder(Node* root) { //use queue data structure 
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node *temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        }else {
            cout<<temp->data;
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right) 
                q.push(temp->right);
        }
    }
}
int main()
{
  
    cout<<"Give PreOrder input"<<endl;
    Node* root = preOrderBuildTree(); //input is in preorder //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    cout<<"Give level Order Input"<<endl;
    Node* root1 = levelOrderBuild(); // input is in level order // 1 2 3 4 5 -1 6 -1 -1 -1 -1 7 -1 -1 -1
    cout<<"print Level order of both trees"<<endl;
    printLevelOrder(root);
    cout<<endl;
    printLevelOrder(root1);
    return 0;
}
//OUTPUT
/*
print Level order of both trees
1
23
456
7

1
23
456
7
*/
