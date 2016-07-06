class Solution{
public:
	ListNode* detectCycle(ListNode* head){
		if(head==NULL)	return NULL;
		ListNode* fastprt = head;
		ListNode* slowptr = head;
		while(fastprt!=NULL){
			fastprt = fastprt->next;
			if(fastprt==NULL)
				return NULL;
			fastprt = fastprt->next;
			if(fastprt==NULL)
				return NULL;
			slowptr = slowptr->next;
			if(fastprt==slowptr)
				break;
		}
		slowptr = head;
		while(fastprt!=slowptr){
			fastprt = fastprt->next;
			slowptr = slowptr->next;
		}
		return fastprt;
	}
}