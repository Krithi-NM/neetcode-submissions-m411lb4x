class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {  
        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        if (size == n) {
            return head->next;
        }

        ListNode* prev = head;
        for (int i = 0; i < (size - n - 1); i++) {
            prev = prev->next;
        }
        ListNode* todel = prev->next;
        prev->next = prev->next->next;
        return head;
    }
};