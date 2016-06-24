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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* temp2 = head;
        int count=0;
        while(temp!=NULL){
            if(temp->val!=val){
                temp2->val = temp->val;
                if(temp->next!=NULL)
                    temp2 = temp2->next;
                count++;
            }
            temp = temp->next;
        }
        int i=0;
        temp2 = head;
        while(i<count-1){
            temp2 = temp2->next;
            i++;
        }
        temp2->next = NULL;
        if(temp2->val!=val)
            return head;
        return NULL;
    }
};