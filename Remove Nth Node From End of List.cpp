class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n){
		if(head==NULL) return NULL;
		int len1 = 0;
		ListNode* tmp = head;
		while(tmp!=NULL){
			len1++;
			tmp = tmp->next;
		}
		int l = len1;
		tmp = head;
		while(len1-n-1>0){
		 tmp = tmp->next;
		 len1--;
		}
		if(tmp==head && n==l)
			head = tmp->next;
		else if(tmp->next!=NULL)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		return head;
    }
}