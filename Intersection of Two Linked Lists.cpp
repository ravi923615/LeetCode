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
    int getLen(ListNode* head){
        int i=0;
        while(head!=NULL){
            i++;
            head = head->next;
        }
        return i;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        int len1 = getLen(headA);
        int len2 = getLen(headB);
        if(len1>len2) swap(headA,headB);
        int x=0;
        while(x!=abs(len1-len2)){
            headB = headB->next;
            x++;
        }
        while(headA!=NULL){
            if(headA==headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};