class MinStack {
    vector<int> minArr;
    vector<int> arr;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);
        if(minArr.empty() || minArr.back() >= val){
            minArr.push_back(val);
        }
    }
    
    void pop() {
        if(!arr.empty()){
            if(!minArr.empty() && arr.back() == minArr.back()){
                minArr.pop_back();
            }
            arr.pop_back();
        }
    }
    
    int top() {
        if(!arr.empty()){
            return arr.back();
        }
        return -1;
    }
    
    int getMin() {
        if(arr.empty()) return -1;
        return minArr.back();
    }
};
