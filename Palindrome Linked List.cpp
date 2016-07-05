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
    ListNode* reverselist(ListNode* head,ListNode* mhead){
        ListNode* prev = NULL;
        ListNode* nxt = head->next;
        ListNode* cur = head;
        ListNode* tmp = mhead;
        while(nxt!=NULL){
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        while(tmp->next!=head) tmp = tmp->next;
        tmp->next = cur;
        return tmp->next;
        
    }
    bool isPalindrome(ListNode* head) {
        if(!head || head->next==NULL)
            return 1;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        ListNode* start = head;
        int fstsum = 0;
        int endsum = 0;
        while(fastptr!=NULL){
            slowptr = slowptr->next;
            if(fastptr->next!=NULL)
                fastptr = fastptr->next->next;
            else 
                fastptr = fastptr->next;
        }
        ListNode* mid = reverselist(slowptr,head);
        ListNode* tmp = head;
        while(mid!=NULL){
            if(tmp->val!=mid->val)
                return 0;
            mid = mid->next;
            tmp= tmp->next;
        }
        return 1;
    }
};