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
    ListNode* findAndRemoveLastNode(ListNode* head){
        ListNode* temp = head;
        if(head==nullptr || head->next == nullptr) return head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = nullptr;
        // cout<<"last Node is "<<ans->val<<endl;
        return ans;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next == nullptr || head->next->next == nullptr) return;
        ListNode* temp1 = head, *temp2 = head->next;
        temp1->next = findAndRemoveLastNode(temp2);
        temp1 = temp1->next;
        temp1->next = temp2;
        reorderList(temp2);
    }
};

