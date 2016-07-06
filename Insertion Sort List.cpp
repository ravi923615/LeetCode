class Solution{
public:
	ListNode* insertionSortList(ListNode* head){
		if(head==NULL || head->next==NULL)
			return head;
		ListNode* comp1 = head;
		ListNode* comp2 = head;
		while(comp1!=NULL){
			while(comp2!=NULL){
				if(comp1->val>comp2->val)
					swap(comp1->val,comp2->val);
				comp2 = comp2->next;
			}
			comp1 = comp1->next;
			comp2 = comp1;
		}
		return head;
	}
}