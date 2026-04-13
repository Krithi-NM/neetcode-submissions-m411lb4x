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
    ListNode*merge(ListNode*head1,ListNode*head2){
        if(head1==NULL || head2==NULL){
            return head1==NULL ? head2:head1;
        }
        if(head1->val < head2->val){
            head1->next = merge(head1->next, head2);
            return head1;
        }else{
            head2->next=merge(head2->next,head1);
            return head2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;

    for(int i = 0; i < lists.size(); i++){
        ans = merge(ans, lists[i]);
    }

    return ans;
        
    }
};
