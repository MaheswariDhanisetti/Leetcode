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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }

        while(head!=nullptr && mp[head->val]>0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }

        ListNode* curr=head;

        while(curr!=nullptr && curr->next!=nullptr){

            if(mp[curr->next->val]>0){
                ListNode* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }
            else curr=curr->next;
        }

        return head;
    }
};