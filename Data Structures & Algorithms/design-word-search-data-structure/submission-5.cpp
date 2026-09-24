class Node{
    public:
    bool isEnd;
    vector<Node*> next;
    Node(){
        isEnd = false;
        next.resize(26, nullptr);
    }
};
class WordDictionary {
    Node * head;
public:
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node * temp = head;
        for(char c : word){
            if(temp->next[c-'a']==nullptr){
                temp->next[c-'a'] = new Node();
            }
            temp = temp->next[c-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        return solve(word, 0, head);
    }
    bool solve(string &word, int i, Node * head){
        if(head == nullptr) return false;
        if(i>=word.size()) return head->isEnd;
        bool ans = false;
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                ans = ans || solve(word, i+1, head->next[j]);
                if(ans==true) return true;
            }
        }else{
            ans = head->next[word[i]-'a'] != nullptr && solve(word, i+1, head->next[word[i]-'a']);
        }
        return ans;
    }
};
