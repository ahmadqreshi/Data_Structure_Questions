/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL) { // in case of 1->2 when fast = null in 1st iteration then fast -> next not exist so both condition are necessary
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false; 
    }
};
