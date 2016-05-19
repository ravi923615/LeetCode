/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* nxt = head->next;
        ListNode* cur = head;
        while(nxt!=NULL){
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        head = cur;
        return head;
    }
};