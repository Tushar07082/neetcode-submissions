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
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr, *curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k==1) return head;

        ListNode dummy(0, head);
        ListNode* temp = &dummy;

        int x = 0;
        while(x<k && temp->next != nullptr){
            temp = temp->next;
            x++;
        }

        if(x<k) return head;

        ListNode* nextPart = reverseKGroup(temp->next, k);
        temp->next = nullptr;


        temp = reverse(head);
        head->next = nextPart;

        return temp;
    }
};
