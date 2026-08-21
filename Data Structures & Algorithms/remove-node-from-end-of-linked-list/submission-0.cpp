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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head, *temp2 = head;
        int i =0;
        while(temp1->next != nullptr && i<n){
            temp1 = temp1->next;
            i++;
        }
        if(i<n && temp1->next == nullptr){
            return head->next;
        }
        while(temp1->next != nullptr){
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        ListNode *temp3 = temp2->next;
        temp2->next = temp2->next->next;
        temp3->next = nullptr;
        return head;
    }
};
