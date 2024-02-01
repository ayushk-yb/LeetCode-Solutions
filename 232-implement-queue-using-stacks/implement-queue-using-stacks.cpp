class MyQueue {
public:
    stack<int> ipStack;
    stack<int> opStack;
    MyQueue() {
    }
    
    void push(int x) {
        ipStack.push(x);
    }
    
    int pop() {
        if(opStack.empty())
        {
            while(!ipStack.empty())
            {
                opStack.push(ipStack.top());
                ipStack.pop();
            }
        }
        
        if(!opStack.empty())
        {
            int front = opStack.top();
            opStack.pop();
            return front;
        }

        return -1;
    }
    
    int peek() {
        if(opStack.empty())
        {
            while(!ipStack.empty())
            {
                opStack.push(ipStack.top());
                ipStack.pop();
            }
        }
        if(!opStack.empty())
        {
            return opStack.top();
        }

        return -1;
    }
    
    bool empty() {
        return ipStack.empty() && opStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */