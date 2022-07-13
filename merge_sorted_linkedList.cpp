/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// method 1 by creating another linkList
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while(list1!=NULL and list2!=NULL) {
            if(list1->val<=list2->val){
                ans->next = new ListNode(list1->val);
                list1 = list1->next;
            }else {
                ans->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            ans = ans->next;
        }
        while(list1){
            ans->next = new ListNode(list1->val);
            list1 = list1->next;
            ans = ans->next;
        }
        while(list2){
            ans->next = new ListNode(list2->val);
            list2 = list2->next; 
            ans = ans->next;
        }
        return head->next;
    }
};

//method 2 - by using existing linkedList optimize way
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* lst1, ListNode* lst2) {
       ListNode*head,*tail=new ListNode();
        head=tail;
        while(lst1 && lst2){
            if(lst1->val<=lst2->val){
                tail->next=lst1;
                lst1=lst1->next;
            }else{
                tail->next=lst2;
                lst2=lst2->next;
            }
            tail=tail->next;
        }
        while(lst1){
            tail->next=lst1;
            tail=tail->next;
            lst1=lst1->next;
        }
        while(lst2){
            tail->next=lst2;
            lst2=lst2->next;
            tail=tail->next;
            
        }
        return head->next;
        
        
    }
};
