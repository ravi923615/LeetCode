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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        map<int,int> hash;
        ListNode* results=NULL;
        for(int i=0;i<lists.size();i++){
            while(lists[i]!=NULL){
                hash[lists[i]->val]++;
                lists[i] = lists[i]->next;
            }
        }
        for(map<int,int>::reverse_iterator it=hash.rbegin();it!=hash.rend();++it){
            int m= it->second;
            while(m!=0){
                if(results==NULL){
                results = (ListNode*)malloc(sizeof(ListNode));
                results->val = it->first;
                results->next = NULL;
            }else{
                ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
                temp->val = it->first;
                temp->next = results;
                results = temp;
            }
                m--;
            }
        }
        return results;
    }
};