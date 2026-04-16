class MinStack {
private:
    stack<long long>st;
    long long minval;
public:
    MinStack() {
        minval=LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minval=val;
        }else{
            if(val>=minval){
                st.push(val);
            }else{
                st.push(2LL*val-minval);
                minval=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long topval=st.top();
        st.pop();
        if (topval<minval){
            minval= 2LL*minval-topval;
        }  
    }
    
    int top() {
        long long topval=st.top();
        if (topval>minval){
            return (int)topval;
        }else{
            return (int)minval;
        }
    }
    
    int getMin() {
        return (int)minval;
    }
};
