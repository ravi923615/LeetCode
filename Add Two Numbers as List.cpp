class Solution{
public:
	int getListLen(ListNode* head){
		ListNode* tmp = head;
		int len = 0;
		while(tmp!=NULL){
			len++;
			tmp = tmp->next;
		}
		return len;
	}
	ListNode* addTwoNumbers(ListNode* A, ListNode* B){
		int len1 = getListLen(A);
		int len2 = getListLen(B);
		if(len1<len2)
			swap(A,B);
		int carry = 0;
		ListNode* resHead = NULL;
		ListNode* tail = NULL;
		while(B || carry){
			int sum = (A!=NULL?A->val:0)+(B!=NULL?B->val:0)+carry;
			if(sum>9){
				carry = sum/10;
				sum = sum%10;
			}
			ListNode* tmp = new ListNode(sum);
			if(resHead==NULL){
				resHead = tmp;
				tail = resHead;
			}else{
				resHead->next = tmp;
				resHead = tmp;
			}
		}
		return resHead;
	}
}