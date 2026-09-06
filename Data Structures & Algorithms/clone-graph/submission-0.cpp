/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> copy;
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        
        Node* ans = new Node(node->val);
        copy[node] = ans;

        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node *curr = q.front();q.pop();
            for(auto i: curr->neighbors){
                if(copy.find(i) == copy.end()){
                    Node* newNode = new Node(i->val);
                    copy[i] = newNode;
                    copy[curr]->neighbors.push_back(newNode);
                    q.push(i);
                }else{
                    copy[curr]->neighbors.push_back(copy[i]);
                }
            }
            
        }
        return ans;
    }
};
