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
        priority_queue<ListNode* , vector<ListNode*>, Compare> pq;

        for(int i=0;i<n;i++){
            if(lists[i] != nullptr) pq.push(lists[i]);
        }

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            ansTemp->next = temp;
            if(temp->next != nullptr) pq.push(temp->next);
            ansTemp = ansTemp->next;
        }
        ansTemp->next = nullptr;

        return dummy.next;
        
    }
};
