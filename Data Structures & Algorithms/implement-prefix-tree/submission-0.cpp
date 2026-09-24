class Node {
    public:
    bool isEnd;
    vector<Node*> next;
    Node(){
        isEnd = false;
        next.resize(26, nullptr);
    }
};
class PrefixTree {
    Node * head;
public:
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
        Node * temp = head;
        for(int i=0;i<word.size();i++){
            if(temp->next[word[i]-'a']==nullptr){
                temp->next[word[i]-'a'] = new Node();
            }
            temp = temp->next[word[i]-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node * temp = head;
        for(int i=0;i<word.size();i++){
            if(temp->next[word[i]-'a']==nullptr){
                return false;
            }
            temp = temp->next[word[i]-'a'];
        }
        if(temp->isEnd == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node * temp = head;
        for(int i=0;i<prefix.size();i++){
            if(temp->next[prefix[i]-'a']==nullptr){
                return false;
            }
            temp = temp->next[prefix[i]-'a'];
        }
        return true;
    }
};
