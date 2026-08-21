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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* findSecondHalf(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast!= nullptr && fast->next != nullptr){
            cout<<1<<endl;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        return ans;
    }
    void mergeAlternates(ListNode * head1, ListNode *head2){
        ListNode* temp1 = head1, *temp2 = head2;
        while(temp1 != nullptr && temp2 != nullptr){
            ListNode* x = temp1->next;
            ListNode* y = temp2->next;
            temp1->next = temp2;
            temp2->next = x;
            temp1 = x;
            temp2 = y;
        }
    }
    void reorderList(ListNode* head) {
        ListNode* head2 = findSecondHalf(head);
        head2 = reverseList(head2);
        mergeAlternates(head, head2);
    }
};
