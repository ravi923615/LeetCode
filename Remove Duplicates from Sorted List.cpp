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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* temp = head->next;
        ListNode* tmp = head;
        while(temp!=NULL){
            if(tmp->val==temp->val){
                temp = temp->next;
            }else{
                tmp->next = temp;
                tmp = temp;
                temp = temp->next;
            }
        }
        tmp->next = temp;
        return head;
    }
};