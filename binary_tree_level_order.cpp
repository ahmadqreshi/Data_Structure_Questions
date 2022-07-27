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
    //input //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    // int n = sizeof(arr)/sizeof(int);
    // while(n>=0) {
    //     buildTree();
    //     n--;
    // }
    Node* root = buildTree();
    printLevelOrder(root);
    return 0;
}
//OUTPUT
/*
1
23
456
7
*/
