/*
Given the head of a linked list and an integer val,
remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        while(head!=NULL and head->val==val){
            head = head->next;
            delete temp;
            temp = head;
        }
        while(temp!=NULL and temp->next!=NULL) {
            if(temp->next->val==val){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }else {
                temp = temp->next;
            }
        }
        return head; 
    }
};
