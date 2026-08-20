class Solution {
public:

    string encode(vector<string>& strs) {
        string answer = "";
        for(string str: strs){
            answer += to_string(str.size());
            answer = answer+'#';
            answer = answer + str;
        }
        return answer;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        string curr = "";
        string lenOfCurr = "";
        int length = -1;
        cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            if(s[i] == '#' && length == -1 && lenOfCurr != ""){
                length = stoi(lenOfCurr);
                for(int j=1;j<=length;j++){
                    curr += s[j+i];
                }
                answer.push_back(curr);
                i = i+curr.size();
                curr = "";
                length = -1;
                lenOfCurr = "";
            }else{
                lenOfCurr += s[i];
            }
        }
        return answer;
    }
};
