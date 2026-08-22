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
        Node* original = head;

        while(original != nullptr){
            Node* copy = original->next;
            Node* nextOriginal = copy->next;
            if(nextOriginal != nullptr){
                copy->next = nextOriginal->next;
            }
            original->next = nextOriginal;
            original = nextOriginal;
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
