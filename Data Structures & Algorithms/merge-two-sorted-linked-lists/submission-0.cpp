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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *newList = nullptr, *newTemp = nullptr;
        ListNode *temp1 = list1, *temp2 = list2;

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                if(newTemp == nullptr){
                    newTemp = temp1;
                    newList = newTemp;
                }else{
                    newTemp->next = temp1;
                    newTemp = temp1;
                }
                temp1 = temp1->next;
            }else{
                if(newTemp == nullptr){
                    newTemp = temp2;
                    newList = temp2;
                }else{
                    newTemp->next = temp2;
                    newTemp = temp2;
                }
                temp2 = temp2->next;
            }
        }

        while(temp1 != nullptr){
            newTemp->next = temp1;
            newTemp = temp1;
            temp1 = temp1->next;
        }

        while(temp2 != nullptr){
            newTemp->next = temp2;
            newTemp = temp2;
            temp2 = temp2->next;
        }

        return newList;

    }
};
