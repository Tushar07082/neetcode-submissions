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
    Node* copyOf(Node* a, unordered_map<Node*,Node*> &mpp){
        if(a==nullptr) return nullptr;
        if(mpp.find(a) == mpp.end()){
            Node* newNode = new Node(a->val);
            mpp[a] = newNode;
        }
        return mpp[a];
    }
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
            
        unordered_map<Node* , Node*> mpp;

        Node* newHead = new Node(head->val);
        Node *temp1 = newHead, *temp2 = head;
        mpp[head] = newHead;
        while(temp2 != nullptr){
            temp1->next = copyOf(temp2->next, mpp);
            temp1->random = copyOf(temp2->random, mpp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return newHead;
    }
};
