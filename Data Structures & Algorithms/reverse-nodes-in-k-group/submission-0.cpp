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

class Solution {
public:
   ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prevGroupEnd = dummy;

    while (true) {
        ListNode* kth = prevGroupEnd;
        for (int i = 0; i < k; i++) {
            kth = kth->next;
            if (!kth) return dummy->next; 
        }
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* nextGroupStart = kth->next;
        ListNode* prev = nextGroupStart;
        ListNode* curr = groupStart;

        while (curr != nextGroupStart) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        prevGroupEnd->next = kth;
        prevGroupEnd = groupStart;
     }
   }
};
