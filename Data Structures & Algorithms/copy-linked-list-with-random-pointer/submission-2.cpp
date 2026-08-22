/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node * makeCopies(Node* head){
        Node* curr = head;
        while(curr != nullptr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }
        return head;
    }

    Node* initializeRandoms(Node * head){
        Node* curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr){
                curr->next->random = curr->random->next;
            }else{
                curr->next->random = nullptr;
            }
            
            curr = curr->next->next;
        }
        return head;
    }

    Node * separateTheCopiedList(Node * head){
        Node* ans = head->next;
        Node* temp1 = head->next;

        while(temp1->next != nullptr){
            temp1->next = temp1->next->next;
            temp1 = temp1->next;
        }
        return ans;
    }
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        head = makeCopies(head);
        head = initializeRandoms(head);
        return separateTheCopiedList(head);
    }
};
