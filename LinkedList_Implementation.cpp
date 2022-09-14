#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
    node(int number){
        data = number;
        next = NULL;
    }
};
class LinkedList {
    node *head = NULL;
    public:
    void insert(int data) {
        node *newNode = new node(data);
        if(head==NULL) {
            head = newNode;
            return;
        }
        node *ptr = head;
        while(ptr->next!=NULL) {
            ptr = ptr -> next;
        }
        ptr->next = newNode;
    }
    void printList() {
        node* ptr = head;
        while(ptr!=NULL) {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
    void removeLast() {
        node *ptr = head;
        if(head==NULL) {
            cout<<"LinkedList is empty";
            return;
        } else if(head->next==NULL) {
            head = NULL;
            return;
        } else {
            while(ptr->next->next!=NULL) {
                ptr = ptr->next;
            }
            delete(ptr->next);
            ptr->next = NULL;
        }
    }
    int size() {
        node* ptr = head;
        int count = 0;
        while(ptr!=NULL) {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    void insertAt(int pos,int data) {
        node *newNode = new node(data);
        if(pos > size()+1) {
            cout<<"array has a size of "<<size()<<endl;
            return;
        }
        if(pos==0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        node *ptr = head;
        node *prev;
        int count = 0;
        while(count!=pos and ptr!=NULL) {
            count++;
            prev = ptr;
            ptr = ptr->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    void removeAt(int pos) {
        if(head == NULL) {
            cout<<"Array is empty"<<endl;
            return;
        }
        if(pos > size()) {
            cout<<"out of index"<<endl;
            return;
        }
        if(pos==0) {
            node* temp = head;
            head = head->next;
            delete(temp);
            return;
        }
        int count = 0;
        node* prev;
        node* ptr = head;
        while(count!=pos and ptr->next!=NULL) {
            prev = ptr;
            count++;
            ptr = ptr -> next;
        }
        prev->next = ptr->next;
        delete(ptr);
    }
    
    void reverseList() {
        node*cur = head;
        node*prev = NULL;
        node*temp;
        while(cur!=NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head = prev;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.printList(); //1 2 3 4 5 6
    cout<<endl;
    l1.removeLast(); 
    l1.printList(); //1 2 3 4 5
    cout<<endl;
    l1.insertAt(0,8);
    l1.printList(); //8 1 2 3 4 5 
    cout<<endl;
    l1.removeAt(0);
    l1.printList(); //1 2 3 4 5
    cout<<endl;
    l1.reverseList();
    l1.printList(); //5 4 3 2 1
    return 0;
}
