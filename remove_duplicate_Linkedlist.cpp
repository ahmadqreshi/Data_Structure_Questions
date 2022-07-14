//Remove Duplicates from Sorted List
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail = head;
        while(tail!=NULL and tail->next!=NULL) {
            if (tail->val == tail->next->val) {
                tail->next = tail->next->next;
            }else {
                tail = tail->next;
            }
        }
        return head;
    }
};
