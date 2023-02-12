/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insertAtTail(ListNode* &head,int val){
        
        ListNode* n = new ListNode(val);
        if(head==NULL){
            head=n;
            return;
        }
        ListNode* temp =head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
       ListNode* t=NULL;
        
       priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
           { auto xx=make_pair(lists[i]->val,i);
               minh.push(xx);
               //lists[i]=lists[i]->next;
            
            }
        }
        while(minh.size()){
            auto x=minh.top();
            auto y=x.second;
            minh.pop();
            
                if(lists[x.second]!=NULL){
                    insertAtTail(t,x.first);
                    lists[x.second]=lists[x.second]->next;
                    if(lists[x.second]!=NULL){
                        auto xxx=make_pair(lists[x.second]->val,x.second);
                        minh.push(xxx);
                    }
                
                }
                 
            
        }
        
        return t;
    }
};