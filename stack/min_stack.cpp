#include<bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<int> s;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(min.empty())
        {
            min.push(value);
        }else if(value<=min.top()){
            min.push(value);
        }
    }
    
    void pop() {
        if(s.top()==min.top())
        {
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

//OR


class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty())
        {
            s.push({value,value});
        }else
        {
            int min_value=min(value,s.top().second);
            s.push({value,min_value});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

//OR
class MinStack {
public:
    stack<long long int> s;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            minVal=val;
        }else
        {
            if(val<minVal)
            {
                s.push((long long)2*val-minVal);
                minVal=val;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top()<minVal)
        {
            minVal=2*minVal-s.top();
        }

        s.pop();
    }
    
    int top() {
        if(s.top()<minVal)
        {
            return minVal;
        }

        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */