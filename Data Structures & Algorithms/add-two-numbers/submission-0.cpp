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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        
        int sum = temp1->val + temp2->val;
        int carry = sum/10;
        sum = sum%10;

        ListNode* ans = new ListNode(sum);
        ListNode* temp3 = ans;
        while(temp1->next !=nullptr && temp2->next !=nullptr){
            int sum = temp1->next->val + temp2->next->val + carry;
            carry = sum/10;
            sum = sum%10;

            temp3->next = new ListNode(sum);
            temp3 = temp3->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 -> next != nullptr){
            int sum = temp1->next->val + carry;
            carry = sum/10;
            sum = sum%10;

            temp3->next = new ListNode(sum);
            temp3 = temp3->next;
            temp1 = temp1->next;
        }

        while(temp2 -> next != nullptr){
            int sum = temp2->next->val + carry;
            carry = sum/10;
            sum = sum%10;

            temp3->next = new ListNode(sum);
            temp3 = temp3->next;
            temp2 = temp2->next;
        }

        if(carry != 0){
            temp3->next = new ListNode(carry);
            temp3 = temp3->next;
        }

        return ans;

    }
};
