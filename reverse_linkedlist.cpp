//method 1 by using array
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0;i<arr.size()/2;i++) {
            swap(arr[i],arr[arr.size()-i-1]);
        }
        ListNode* tail = head;
        int k=0;
        while(tail) {
            tail->val = arr[k++];
            tail = tail->next;
        }
        
        return head;
    }
};
//method 2 - by using three variables
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp;
        while(cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};
