class Solution{
public:
	ListNode* sortList(ListNode* head){
		if(head==NULL) return NULL;
		std::vector<int> getval;
		ListNode* tmp = head;
		while(tmp!=NULL){
			getval.push_back(tmp->val);
			tmp = tmp->next;
		}
		sort(getval.begin(), getval.end());
		tmp = head;
		int i=0;
		while(tmp!=NULL){
			tmp->val = getval[i++];
			tmp = tmp->next;
		}
		return head;
	}
}