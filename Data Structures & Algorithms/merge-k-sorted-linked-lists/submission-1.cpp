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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* ansTemp = &dummy;

        int n = lists.size();
        vector<ListNode*> temp(n,nullptr);
        priority_queue<ListNode* , vector<ListNode*>, Compare> pq;

        for(int i=0;i<n;i++){
            temp[i] = lists[i];
            while(temp[i] != nullptr){
                pq.push(temp[i]);
                temp[i] = temp[i]->next;
            }
        }

        while(!pq.empty()){
            ansTemp->next = pq.top();
            ansTemp = ansTemp->next;
            pq.pop();
        }

        return dummy.next;
        
    }
};
